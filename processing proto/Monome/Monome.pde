
import oscP5.*;
import netP5.*;

boolean record = false;

Scroller mScroller = new Scroller();

OscP5 oscP5;
NetAddress myRemoteLocation;

int w = 150;
final int N_BUTTONS_X = 16; // how many buttons across
final int N_BUTTONS_Y = 14; // how many buttons across

ArrayList<Button> mButtons = new ArrayList<Button>();

void setup() {
  
  size(w * N_BUTTONS_X,w * N_BUTTONS_Y, P3D);
  frameRate(60);
  oscP5 = new OscP5(this,12000);

  //myRemoteLocation = new NetAddress("127.0.0.1",9001);
  myRemoteLocation = new NetAddress("192.168.0.26",9001);
  
  open( sketchPath("run.bat"));
 
  this.registerDispose( new ExitHandler() );
  
  float bsize = w;
  
  float xp = 0, yp = 0;
  for( int i = 0; i < N_BUTTONS_Y; ++i ){
    for( int j = 0; j < N_BUTTONS_X; ++j ){
      mButtons.add( new Button( xp , yp , bsize, j , i ) );
      xp += bsize; 
    }
    xp = 0;
    yp += bsize;
  }  
}

void draw() {
  
  if( frameCount % 15 == 0)
    mScroller.update();
  
  stroke(0);
  background(0);
  for( Button b : mButtons )
    b.render();

}

void mousePressed(){
  for( Button b : mButtons )
    b.checkMouse();
}

void sendScaleNote( int in ){
  OscMessage myMessage = new OscMessage("/test");
  myMessage.add(in); /* add an int to the osc message */
  oscP5.send(myMessage, myRemoteLocation); 
}

void keyPressed(){
  
  if( key == 'r' ){
    record = !record;
    return;
  }

  for( Button b : mButtons ){
    b.life = 1;
  }

}

void stop(){
  open(sketchPath("close.bat"));
}

void sendPosBased( int x , int y ){
  sendScaleNote( N_BUTTONS_Y - y );
}

public class ExitHandler{
  public void dispose(){
   open( sketchPath("close.bat") );
  }
}
