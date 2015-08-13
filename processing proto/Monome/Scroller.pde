
class Scroller{
  int step = 0;
  void update(){
    step = (step+1) % N_BUTTONS_X;
    
    for( Button b : mButtons ){
      if( b.ix == step )
        b.tryFire();
    }
    
  }
}
