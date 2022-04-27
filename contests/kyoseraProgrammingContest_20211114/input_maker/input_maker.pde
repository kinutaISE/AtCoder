int n = 1000 ;
void setup() {
  PrintWriter pw = createWriter("input.csv") ;
  for (int i = 0 ; i < n ; i++) {
    int a = (int) random(0, 800) ;
    int b = (int) random(0, 800) ;
    int c = 0 ;
    int d = 0 ;
    while (true) {
      c = (int) random(0, 800) ;
      d = (int) random(0, 800) ;
      if (c != a || d != b)
        break ;
    }
    pw.println(a + " " + b + " " + c + " " + d) ;
  }
  pw.flush() ;
  pw.close() ;
  exit() ;
}
