<?php namespace Track ;

class FareCalculator
{
  // プロパティ
  /*
    レコードを保持する配列
      - 各要素は配列であり、以下のキーと値を持つ
        - キー：時刻 / 値：hh:mm:ss.fff 形式の文字列
        - キー：走行距離 / 値：前回からの走行距離（単位はメートル）
  */
  private $records ;
  // 直前に処理したレコードの時刻（hh:mm:ss.fff（文字列））形式で保持
  private $previous_time ;
  // 総走行距離
  private $total_distance ;
  // 低速走行時間
  private $total_lowspeed_time ;

  // コンストラクタ
  public function __construct($records)
  {
    // 前提：$records は仕様に従った入力である
    $this->set_records($records) ;
  }

  // メソッド
  // $records をキーを設定しながら $this->records にセットする
  public function set_records($records)
  {
    // キーの設定
    $keys = ['時刻', '走行距離'] ;
    // $this->records へのセット
    foreach ($records as $record)
      $this->records[] = array_combine(
        $keys, explode(' ', $record)
      ) ;
  }
  // 全てのレコードを処理する
  public function process_all()
  {
    // 初乗りレコードを処理する
    $this->process_first() ;
    // 以降のレコードを処理する
    while ( !empty($this->records) )
      $this->process_once() ;
  }
  // 初乗りレコードを処理する
  public function process_first()
  {
    // 処理するレコードを取り出す
    $record = $this->records[0] ;
    // 直前に処理したレコードの時刻を初乗りレコードの時刻で初期化する
    $this->previous_time = $record['時刻'] ;
    // 総走行距離を初乗りレコードの距離（0.0）で初期化する
    $this->total_distance = $record['走行距離'] ;
    // 深夜帯を考慮した走行距離を計算する
    $this->total_distance *= ( is_midnight($this->previous_time) ? FARE_INFO['深夜']['割増率'] : 1 ) ;
    // 総運賃を初乗り運賃で初期化する
    $total_fare = FARE_INFO['初乗り']['運賃'] ;
    // 低速走行時間を初期化する
    $this->total_lowspeed_time = 0 ;
    // 処理したレコードを削除する
    array_shift($this->records) ;
  }
  // 2行目以降のレコードを処理する
  public function process_once()
  {
    // 処理するレコードを取り出す
    $record = $this->records[0] ;

    // レコードの時刻と前回レコードからの走行距離を取り出す
    $time = $record['時刻'] ;
    $distance = $record['走行距離'] ;

    // 低速走行であった場合、低速走行時間に加算する
    // 低速走行時間を求める
    $low_speed_time =
      is_lowspeed($this->previous_time, $time, $distance) ?
        time_diff($this->previous_time, $time) : 0 ;
    // 深夜帯を考慮した低速走行時間を求める
    $low_speed_time *= ( is_midnight($time) ? FARE_INFO['深夜']['割増率'] : 1 ) ;

    // 低速走行時間に加算する
    $this->total_lowspeed_time += $low_speed_time ;

    // 深夜帯を考慮した前回レコードからの走行距離を計算する
    $distance *= ( is_midnight($time) ? FARE_INFO['深夜']['割増率'] : 1 ) ;

    // 総走行距離に加算する
    $this->total_distance += $distance ;
    // 直前に処理したレコードの時刻を更新する
    $this->previous_time = $time ;

    // 処理したレコードを削除する
    array_shift($this->records) ;
  }

  // 総運賃を返す
  function get_total_fere()
  {
    // 初乗り運賃で初期化
    $total_fare = FARE_INFO['初乗り']['運賃'] ;

    // 加算運賃に関する計算 //////////////////////////////////
    // 初乗り距離を超えた走行距離を求める
    $distance_over = max(
      0, $this->total_distance - FARE_INFO['初乗り']['上限距離']
    ) ;
    // 加算運賃の単位距離を超えた回数だけ加算する
    $total_fare +=
      FARE_INFO['加算']['運賃'] * ceil( $distance_over / FARE_INFO['加算']['更新距離'] ) ;

    // 低速運賃に関する計算 //////////////////////////////////
    // 低速走行時間が単位時間を超えた回数だけ加算する
    $total_fare +=
      FARE_INFO['低速']['運賃'] * floor( $this->total_lowspeed_time / FARE_INFO['低速']['更新時間'] ) ;

    return $total_fare ;
  }
}
