// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include <unistd.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif
uint32_t prevTime;
// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN4           4
#define PIN3           3

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      16

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN4, NEO_GRB + NEO_KHZ800);
const int buttonPin = 3;
int buttonState = 0;

int delayval   = 500; // delay for half a second
int brightness =  2; //multiplier for intensity. 

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
randomSeed(analogRead(1));
  // End of trinket special code
  pixels.begin(); // This initializes the NeoPixel library.
   
 pinMode(buttonPin, INPUT); 
}



void tits(){
  pixels.setBrightness(95);
  pixels.setPixelColor(0, pixels.Color(8.5*brightness,0*brightness   ,0*brightness));  // red n=0 is center.
  pixels.setPixelColor(1, pixels.Color(0*brightness  ,0*brightness  ,8.5*brightness)); 
  pixels.setPixelColor(2, pixels.Color(8.5*brightness,0*brightness  ,8.5*brightness)); 
  pixels.setPixelColor(3, pixels.Color(8.5*brightness,8.5*brightness,8.5*brightness)); 
  pixels.setPixelColor(4, pixels.Color(0*brightness  ,8.5*brightness,8.5*brightness)); 
  pixels.setPixelColor(5, pixels.Color(3.6*brightness,9.5*brightness,2.5*brightness));
  pixels.setPixelColor(6, pixels.Color(8.5*brightness,5.5*brightness,3.5*brightness));

   pixels.setPixelColor(10, pixels.Color(8.5*brightness,0*brightness   ,0*brightness));  // red n=0 is center.
  pixels.setPixelColor(11, pixels.Color(0*brightness  ,0*brightness  ,8.5*brightness)); 
  pixels.setPixelColor(12, pixels.Color(8.5*brightness,0*brightness  ,8.5*brightness)); 
  pixels.setPixelColor(13, pixels.Color(8.5*brightness,8.5*brightness,8.5*brightness)); 
  pixels.setPixelColor(14, pixels.Color(0*brightness  ,8.5*brightness,8.5*brightness)); 
  pixels.setPixelColor(15, pixels.Color(3.6*brightness,9.5*brightness,2.5*brightness));
  pixels.setPixelColor(16, pixels.Color(8.5*brightness,5.5*brightness,3.5*brightness));

    pixels.setPixelColor(20, pixels.Color(8.5*brightness,0*brightness   ,0*brightness));  // red n=0 is center.
  pixels.setPixelColor(21, pixels.Color(0*brightness  ,0*brightness  ,8.5*brightness)); 
  pixels.setPixelColor(22, pixels.Color(8.5*brightness,0*brightness  ,8.5*brightness)); 
  pixels.setPixelColor(23, pixels.Color(8.5*brightness,8.5*brightness,8.5*brightness)); 
  pixels.setPixelColor(24, pixels.Color(0*brightness  ,8.5*brightness,8.5*brightness)); 
  pixels.setPixelColor(25, pixels.Color(3.6*brightness,9.5*brightness,2.5*brightness));
  pixels.setPixelColor(26, pixels.Color(8.5*brightness,5.5*brightness,3.5*brightness));
  pixels.show();
  delay(9000);
  }

void redstar(){
  pixels.setBrightness(95);
  pixels.clear();
  int i = 1;
  int x = 0;
  while(x<NUMPIXELS){
  for(i = 1; i < NUMPIXELS; i++){
   // pixels.setPixelColor(0, pixels.Color(6.6*brightness,0*brightness,0*brightness)); //red
    pixels.setPixelColor(i, pixels.Color(10*brightness,7*brightness,0*brightness)); //red
    pixels.setPixelColor(i+(NUMPIXELS/2), pixels.Color(16*brightness,10*brightness,0*brightness)); //red
    pixels.show();
  delay(500);
  pixels.clear();
      }
      x++;
      }
}

void colourTest(){
    pixels.clear();
  int i = 1;
  int x = 0;
  while(x<NUMPIXELS/2){
  for(i = 1; i < NUMPIXELS; i++){
   // pixels.setPixelColor(0, pixels.Color(6.6*brightness,0*brightness,0*brightness)); //red
    pixels.setPixelColor(i, pixels.Color(0xFF,0xA5,0x00)); //red
    pixels.setPixelColor(i+16, pixels.Color(0xFF,0xA5,0x00)); //red
    pixels.show();
  delay(200);
  pixels.clear();
      }
      x++;
      }
  }

void flower(){
  //yellow petals red core
    pixels.setBrightness(95);
    pixels.setPixelColor(0, pixels.Color(6.5*brightness,0*brightness,0*brightness)); // red n=0 is center.
    for(int i = 1; i <= NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(3.6*brightness,3.6*brightness,0*brightness)); //yellow
    pixels.show();
    //maybe do a pulse and fade thing IDK
  delay(500);
    }
    delay(10000);
    }

void msltoe(){
  //yellow petals red core
    pixels.setBrightness(95);
    pixels.setPixelColor(0, pixels.Color(6.5*brightness,0*brightness,0*brightness)); // red n=0 is center.
    for(int i = 1; i <= NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(0*brightness,10*brightness,0*brightness)); //green
    
    pixels.show();
    //maybe do a pulse and fade thing IDK
  delay(500);
    }
    pixels.setPixelColor(1, pixels.Color(6.5*brightness,0*brightness,0*brightness));
    pixels.setPixelColor(3, pixels.Color(6.5*brightness,0*brightness,0*brightness));
    pixels.show();
    delay(90000);
    }

void annRand(){
  pixels.setBrightness(95);
  fill(0);
  int Rn = random(0,9);
  int Gn = random(0,9);
  int Bn = random(0,9);
  for(int j = NUMPIXELS/2; j>=0; j--){
      pixels.setPixelColor(j, pixels.Color(Rn*brightness,Gn*brightness,Bn*brightness));
      pixels.setPixelColor(j+16, pixels.Color(Rn*brightness,Gn*brightness,Bn*brightness));
      pixels.show();
      delay(333);
      }
      delay(9001);
  }

void green(){
  pixels.setBrightness(65);
    for(int i=0;i<=NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0*brightness,8.5*brightness,0*brightness)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds) 
  }}

void spinny(){
  uint8_t offset = 0 ; 
  uint8_t  i;
  uint32_t color  = 0xFFB500; // orange?
      for(i=0; i<32; i++) {
      uint32_t c = 0;
      if(((offset + i) & 7) < 2) c = color; // 4 pixels on...
      pixels.setPixelColor(   i, c); // First eye
      pixels.setPixelColor(31-i, c); // Second eye (flipped)
    }
    pixels.show();
    offset++;
    delay(50);
    
  uint32_t t;
  t = millis();
  if((t - prevTime) > 8000) {      // Every 8 seconds...
      color >>= 8;                 // Next color R->G->B
      if(!color) color = 0xFF0000; // Reset to red
    }
    for(i=0; i<32; i++) pixels.setPixelColor(i, 0);
    prevTime = t;
  }
  
void USA(){
  pixels.setBrightness(155);
  pixels.setPixelColor(0, pixels.Color(8.5*brightness,0*brightness   ,0*brightness));  // red n=0 is center.
  pixels.setPixelColor(1, pixels.Color(8.5*brightness  ,0*brightness  ,0*brightness)); 
  pixels.setPixelColor(2, pixels.Color(8.5*brightness,0*brightness  ,0*brightness)); 
  pixels.setPixelColor(4, pixels.Color(8.5*brightness,0*brightness  ,0*brightness)); 
  pixels.setPixelColor(6, pixels.Color(8.5*brightness,0*brightness  ,0*brightness)); 
pixels.setPixelColor(8, pixels.Color(8.5*brightness,0*brightness  ,0*brightness)); 
pixels.setPixelColor(9, pixels.Color(8.5*brightness,0*brightness  ,0*brightness)); 
pixels.setPixelColor(10, pixels.Color(8.5*brightness,0*brightness  ,0*brightness)); 
pixels.setPixelColor(12, pixels.Color(8.5*brightness,0*brightness  ,0*brightness)); 
pixels.setPixelColor(14, pixels.Color(8.5*brightness,0*brightness  ,0*brightness)); 
pixels.setPixelColor(17, pixels.Color(8.5*brightness,0*brightness  ,0*brightness)); 
pixels.setPixelColor(18, pixels.Color(8.5*brightness,0*brightness  ,0*brightness)); 
pixels.setPixelColor(19, pixels.Color(8.5*brightness,0*brightness  ,0*brightness)); 
pixels.setPixelColor(21, pixels.Color(8.5*brightness,0*brightness  ,0*brightness)); 
pixels.setPixelColor(23, pixels.Color(8.5*brightness,0*brightness  ,0*brightness)); 
pixels.setPixelColor(25, pixels.Color(8.5*brightness,0*brightness  ,0*brightness)); 
pixels.setPixelColor(26, pixels.Color(8.5*brightness,0*brightness  ,0*brightness)); 
pixels.setPixelColor(31, pixels.Color(8.5*brightness,0*brightness  ,0*brightness)); 

//Blue
pixels.setPixelColor(27, pixels.Color(0*brightness,0*brightness  ,8.5*brightness)); 
pixels.setPixelColor(28, pixels.Color(0*brightness,0*brightness  ,8.5*brightness)); 
pixels.setPixelColor(29, pixels.Color(0*brightness,0*brightness  ,8.5*brightness)); 
pixels.setPixelColor(30, pixels.Color(0*brightness,0*brightness  ,8.5*brightness)); 

//white
pixels.setPixelColor(3, pixels.Color(8.5*brightness,8.5*brightness  ,8.5*brightness)); 
pixels.setPixelColor(5, pixels.Color(8.5*brightness,8.5*brightness  ,8.5*brightness)); 
pixels.setPixelColor(7, pixels.Color(8.5*brightness,8.5*brightness  ,8.5*brightness)); 
pixels.setPixelColor(11, pixels.Color(8.5*brightness,8.5*brightness  ,8.5*brightness)); 
pixels.setPixelColor(13, pixels.Color(8.5*brightness,8.5*brightness  ,8.5*brightness)); 
pixels.setPixelColor(15, pixels.Color(8.5*brightness,8.5*brightness  ,8.5*brightness)); 
pixels.setPixelColor(16, pixels.Color(8.5*brightness,8.5*brightness  ,8.5*brightness)); 
pixels.setPixelColor(20, pixels.Color(8.5*brightness,8.5*brightness  ,8.5*brightness)); 
pixels.setPixelColor(22, pixels.Color(8.5*brightness,8.5*brightness  ,8.5*brightness)); 
pixels.setPixelColor(24, pixels.Color(8.5*brightness,8.5*brightness  ,8.5*brightness)); 
  pixels.show();
  delay(24000);
  
  }

void fill(int snap){//dual fill with snap
  for(int j = NUMPIXELS/2; j>=0; j--){ //fall all double time
      pixels.setPixelColor(j, 0x00FFFF);
      pixels.setPixelColor(j+16, 0x00FFFF);
      
      pixels.show();
      delay(snap); //snap?
      }
  }
void chan4(){
  //fill(44); 
  pixels.setBrightness(96);
  for(int i=0; i<32; i+=4){
    pixels.setPixelColor(i, pixels.Color(0*brightness,8*brightness   ,0*brightness));
    pixels.setPixelColor(i+1, pixels.Color(0*brightness,8*brightness   ,0*brightness));
    
    }
  pixels.show();
  delay(9000);
  }

void flash(int x){
  int rate = x;
  if(rate!=600){
    rate=rate;
    }else{
      rate=600;
      }
    
pixels.setBrightness(255);
fill(0);
  delay(rate);
pixels.setBrightness(0);
fill(0);
  delay(rate);
  }
  
void fade(){
  int br = 200;           //lower brightness, makes this function shorter
  int rate = 150;         
  int decrement = 10;      //amount removed from brightness
pixels.setBrightness(br); //brightness is 255 (8bit)
fill(0); 
  delay(rate);
for(br; br>=0; br-=decrement){ //decrement 255 -n
pixels.setBrightness(br);
fill(0); //quick fill
  delay(rate);
  }
delay(3000);
  
  }
 
void Randy(){
  pixels.setBrightness(155);
  //32bit rando, rand()only does 16 bit rand.
uint32_t x  = rand() & 0xff;
         x |= (rand() & 0xff) << 8;
         x |= (rand() & 0xff) << 16;
         x |= (rand() & 0xff) << 24;

 //  x;  colour 32b
 for (int i = 0; i < 32; i++){
  pixels.setPixelColor(i,x); 
  pixels.show();
  delay(240);
   }
    delay(24000);
  }
void halo(){
  pixels.clear();
  pixels.setBrightness(30);
  uint32_t x = 0xffff00;
  for (int i = 0; i<20; i++){
    pixels.setPixelColor(i,x); 
    pixels.show();
    delay(240);
    }
    delay(24000);
  }
  
void loop() {

flash(10); //10-20 is awful

fade();
halo();

//spinny();
green();     
tits();
annRand();
flower();
msltoe();
redstar();
//spinny();
//colourTest();
Randy();
USA();
fade();
flash(30);
chan4();

}
