class Button {
  int initLife = -1;
  int life;
  PVector loc;
  float size;
  
  color dcolor = color( 100 );
  color bcolor = color( 255 , 255 , 0 );
  float lit = 0.0f;
  
  int ix, iy;
  
  boolean pressed;
  
  Button( float x , float y , float s, int xx, int yy){
    loc = new PVector( x , y );
    size = s;
    ix = xx;
    iy = yy;
  }
  
  void updateLife(){
    if( life > 0 ){
      life--;
    }
  }
  
  void render(){
    lit *= 0.9;
    fill(dcolor);
    if( !pressed )
      fill( 150 );
    stroke(0, 30);
    rect( loc.x , loc.y, size, size );
    
        fill(lerpColor( dcolor , bcolor , lit ) , 200);
    if( !pressed )
      fill( 150 );
    noStroke();
    
    
    pushMatrix();
    translate(0,0,1);
    float r = (size*1.5) * sin( PI * lit );
    ellipse( loc.x + size/2.0f, loc.y + size/2.0f , r , r  );
    popMatrix();
    
    if( life == 0 && lit < 0.3 ){
      life = -1;
      pressed = false;
    }

    
  }
  
  void checkMouse(){
    if( mouseX > loc.x && mouseX < loc.x + size 
    &&  mouseY > loc.y && mouseY < loc.y + size ){
      onClick();
    }
  }
  
  void onClick(){
    pressed = !pressed;
    life = initLife;
  }
  
  void fire(){
        sendPosBased( ix , iy );
    println(" " + iy );
    lit = 1.0f;
    updateLife();
  }
  
  
  void tryFire(){
    if( pressed ){
      fire();
    }
  }
  
  
}
