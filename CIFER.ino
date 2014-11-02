/****************************************************************************************
font by LG Beard              _              _              _                _       
        /\ \                /\ \           /\ \           /\ \             /\ \     
       /  \ \               \ \ \         /  \ \         /  \ \           /  \ \    
      / /\ \ \              /\ \_\       / /\ \ \       / /\ \ \         / /\ \ \   
     / / /\ \ \            / /\/_/      / / /\ \_\     / / /\ \_\       / / /\ \_\  
    / / /  \ \_\          / / /        / /_/_ \/_/    / /_/_ \/_/      / / /_/ / /  
   / / /    \/_/         / / /        / /____/\      / /____/\        / / /__\/ /   
  / / /                 / / /        / /\____\/     / /\____\/       / / /_____/    
 / / /________  _   ___/ / /__  _   / / /      _   / / /______  _   / / /\ \ \  _   
/ / /_________\/\_\/\__\/_/___\/\_\/ / /      /\_\/ / /_______\/\_\/ / /  \ \ \/\_\ 
\/____________/\/_/\/_________/\/_/\/_/       \/_/\/__________/\/_/\/_/    \_\/\/_/ 
   Commandline     Interpreter         For           Embedded          Risc
---------------------------------------------------------------------------------------

Nick Poole is responsible for this mess.
As long as you retain this notice you can do whatever you want with this stuff. 
If we meet some day, and you think this stuff is worth it, you can buy me a beer in return

This was designed to run on the "SFE-80 micro computer system."

****************************************************************************************/
String user;
String path = "A:>";
String commandPass;

int charcnt = 0;
int linecnt = 16;

void setup() {

  Serial1.begin(9600); //In from keyboard interpreter 
  Serial2.begin(115200); //Out to LCD screen
  
  pinMode(5, OUTPUT); //ZIF Socket power
  digitalWrite(5, LOW);
  
  delay(5000); //Terminal housekeeping, Give Keyboard time to initialize
  clearLCD();    
  delay(2000);
  delay(10);
  
      clearLCD();
    charcnt = charcnt + Serial2.print("                          ");lE();      
    charcnt = charcnt + Serial2.print("    _____ _____ _____     ");lE(); //Title Screen
    charcnt = charcnt + Serial2.print("   I   __I   __I   __I    ");lE();
    charcnt = charcnt + Serial2.print("   I__   I   __I   __I    ");lE();
    charcnt = charcnt + Serial2.print("   I_____I__I  I_____I    ");lE();
    charcnt = charcnt + Serial2.print("         ___ ___          ");lE();
    charcnt = charcnt + Serial2.print("        I _ I   I         ");lE();
    charcnt = charcnt + Serial2.print("        I _ I O I         ");lE();
    charcnt = charcnt + Serial2.print("        I___I___I         ");lE();
    charcnt = charcnt + Serial2.print("                          ");lE();
    charcnt = charcnt + Serial2.print("  MICRO COMPUTER SYSTEM   ");lE();
    charcnt = charcnt + Serial2.print("                          ");lE();
    charcnt = charcnt + Serial2.print(" 'Welcome to the future.' ");lE();
    
    delay(5000);
    
    clearLCD();
  
  charcnt = charcnt + Serial2.print("C.I.F.E.R                 "); lE(); //Intro Line
  charcnt = charcnt + Serial2.print("Commandline Interpreter   "); lE();
  charcnt = charcnt + Serial2.print("For Embedded Risc         "); lE();
  charcnt = charcnt + Serial2.print("Nick Poole (OS)2012       "); lE();

  lineFeed();
  lineFeed();
  
  delay(1000);
  charcnt = charcnt + Serial2.print(path); lE(); //show path
    
}

void loop() {
  
  String command; //setup input 
  
  while(1){
  char in; 
  while(!Serial1.available()){}; //wait on key
  int i = 3 + command.length(); //find line length
  backLCD(i); //back dat ass up
  in = Serial1.read(); //get key
  if(in == 13){interpret();}//interpret command if RTN
  if(in != 0){command += in;} //add to terminal string if it's not a 0 byte
  charcnt = charcnt + Serial2.print(path); lE();
  charcnt = charcnt + Serial2.print(command); lE();
  commandPass = command;}

}

void interpret()
{
  
  lineFeed();
  
  int cmdIndex = commandPass.indexOf(' '); //read up to frist space for command name
  String cmd = commandPass.substring(0,cmdIndex); //keep command name
  String arg = commandPass.substring(cmdIndex); //the rest is the argument
  String argTest = commandPass.substring(cmdIndex, cmdIndex+1); //see if there is an argument
  boolean valid = 0; //this is our valid command flag

  // FAKE EXIT COMMAND v1.0
  //This is a place holder for the exit command
  //of course there is no system to exit to

  if(cmd == "exit"){
  charcnt = charcnt + Serial2.print("Shutdown."); lE(); while(1){};}
  
  // ECHO COMMAND
  //classic DOS ECHO with no options
  if(cmd == "echo"){
    clearLCD();
  charcnt = charcnt + Serial2.print(arg); lE(); valid=1;}
  
  //dummy DIR command
  //give them something to laugh at
  if(cmd == "dir" || cmd == "DIR" || cmd == "Dir"){
    clearLCD();
  charcnt = charcnt + Serial2.print("C.I.F.E.R Runs without    "); lE();
  charcnt = charcnt + Serial2.print("a disk, so there is no    "); lE();
  charcnt = charcnt + Serial2.print("file structure.           "); lE();
  charcnt = charcnt + Serial2.print("What are you doing        "); lE();
  charcnt = charcnt + Serial2.print("snooping anyway? ;)       "); lE();
  
  valid = 1;
  }
  
  //SysInfo COMMAND
  
  if(cmd == "sysinfo"){
    clearLCD();
    charcnt = charcnt + Serial2.print("  ___    ____ ____ ____   ");lE();
    charcnt = charcnt + Serial2.print(" I   ' I I==  I___ I--<'  ");lE();
    charcnt = charcnt + Serial2.print(" I___,.I.I   .I___.I   I  ");lE();
    charcnt = charcnt + Serial2.print("========================= ");lE();
    charcnt = charcnt + Serial2.print("(C)ommand-Line            ");lE();
    charcnt = charcnt + Serial2.print("(I)nterpreter (F)or       ");lE();
    charcnt = charcnt + Serial2.print("(E)mbedded (R)isc         ");lE();
    charcnt = charcnt + Serial2.print("by: Nick Poole 2012       ");lE();
    while(!Serial1.available()){};
    valid=1;}
  
  //CLEAR SCREEN COMMAND "CLS"
  //uses the Ansi terminal library to clear screen and return to home
  
  if(cmd == "cls"){
  clearLCD();
  valid = 1;
  }
  
  //just a utility to show the SFE-80 logo
  
  if(cmd == "title"){
    clearLCD();
    charcnt = charcnt + Serial2.print("                          ");lE();    
    charcnt = charcnt + Serial2.print("    _____ _____ _____     ");lE();
    charcnt = charcnt + Serial2.print("   I   __I   __I   __I    ");lE();
    charcnt = charcnt + Serial2.print("   I__   I   __I   __I    ");lE();
    charcnt = charcnt + Serial2.print("   I_____I__I  I_____I    ");lE();
    charcnt = charcnt + Serial2.print("         ___ ___          ");lE();
    charcnt = charcnt + Serial2.print("        I _ I   I         ");lE();
    charcnt = charcnt + Serial2.print("        I _ I O I         ");lE();
    charcnt = charcnt + Serial2.print("        I___I___I         ");lE();
    charcnt = charcnt + Serial2.print("                          ");lE();
    charcnt = charcnt + Serial2.print("  MICRO COMPUTER SYSTEM   ");lE();
    charcnt = charcnt + Serial2.print("                          ");lE();
    charcnt = charcnt + Serial2.print(" 'Welcome to the future.' ");lE();

    while(!Serial1.available()){};
    valid=1;}
    
  //RUN THE IC COMMAND "RUN"
  //powers the socket, pipes keys to zif and zif to screen
  
  if(cmd == "run" || cmd == "RUN"){
    
    Serial3.begin(1200); //Start ZIF serial
    
    clearLCD(); //Make some room in the terminal
    
    digitalWrite(5, HIGH); //Turn on the ZIF
    
    char rxbuff = 0; //Incoming serial bit
    char txbuff = 0; //Outgoing serial bit
        
    while(rxbuff!=126){ //Break out if you ge the escape key
    
    if(Serial3.available()){ //
    rxbuff = Serial3.read();
    delay(5);
    if(rxbuff==byte(0)){lineFeed();}
    delay(5);
    if(rxbuff==byte(96)){clearLCD();}
    delay(10);
    charcnt = charcnt + Serial2.write(rxbuff); 
    }
    
    delay(10);
    
    if(Serial1.available()){
    txbuff = Serial1.read();
    delay(10);
    if(txbuff == 13){txbuff = 96;}
    delay(5);
    Serial3.write(txbuff);
    }
    
 }
Serial3.end(); 
valid = 1;
digitalWrite(5, LOW);}
  
  if(cmd == "ACP"){
    clearLCD();
   charcnt = charcnt + Serial2.write("ASCII code pass utility"); lineFeed();
   charcnt = charcnt + Serial2.write("press ~ to escape");lineFeed();
   lineFeed();
   while(Serial1.read()!=126){
   if(Serial1.available()){
   charcnt = charcnt + Serial2.print(byte(Serial1.read())); lineFeed();}
   }
  valid = 1; 
  }
  
  if(cmd == "demo"){
    
    while(1){
          clearLCD();
    charcnt = charcnt + Serial2.print("                          ");lE();          
    charcnt = charcnt + Serial2.print("    _____ _____ _____     ");lE(); //COMPUTER HARDWARE
    charcnt = charcnt + Serial2.print("   I   __I   __I   __I    ");lE();
    charcnt = charcnt + Serial2.print("   I__   I   __I   __I    ");lE();
    charcnt = charcnt + Serial2.print("   I_____I__I  I_____I    ");lE();
    charcnt = charcnt + Serial2.print("         ___ ___          ");lE();
    charcnt = charcnt + Serial2.print("        I _ I   I         ");lE();
    charcnt = charcnt + Serial2.print("        I _ I O I         ");lE();
    charcnt = charcnt + Serial2.print("        I___I___I         ");lE();
    charcnt = charcnt + Serial2.print("                          ");lE();
    charcnt = charcnt + Serial2.print("  MICRO COMPUTER SYSTEM   ");lE();
    charcnt = charcnt + Serial2.print("                          ");lE();
    charcnt = charcnt + Serial2.print(" 'Welcome to the future.' ");lE();
          delay(5000);
          if(Serial1.available()){valid = 1; goto breakout;}
          clearLCD();
    charcnt = charcnt + Serial2.print("  ___    ____ ____ ____   ");lE();
    charcnt = charcnt + Serial2.print(" I   ' I I==  I___ I--<'  ");lE(); //INTERPRETER
    charcnt = charcnt + Serial2.print(" I___,.I.I   .I___.I   I  ");lE();
    charcnt = charcnt + Serial2.print("========================= ");lE();
    charcnt = charcnt + Serial2.print("(C)ommand-Line            ");lE();
    charcnt = charcnt + Serial2.print("(I)nterpreter (F)or       ");lE();
    charcnt = charcnt + Serial2.print("(E)mbedded (R)isc         ");lE();
    charcnt = charcnt + Serial2.print("by: Nick Poole 2012       ");lE();
          delay(5000);
          if(Serial1.available()){valid = 1; goto breakout;}
          clearLCD();
    charcnt = charcnt + Serial2.print("                          ");lE();
    charcnt = charcnt + Serial2.print("     POWERED BY ATMEL     ");lE();
    charcnt = charcnt + Serial2.print("                          ");lE();
    charcnt = charcnt + Serial2.print("    ### ###    ##  ### (c)");lE(); //PROCESSOR!!!
    charcnt = charcnt + Serial2.print("    ### ###   ### ######  ");lE();
    charcnt = charcnt + Serial2.print("   ##### ##   ##  ##  ##  ");lE();
    charcnt = charcnt + Serial2.print("   ## ## ### ### ###  ##  ");lE();
    charcnt = charcnt + Serial2.print("  ### ### ## ##  ######   ");lE();
    charcnt = charcnt + Serial2.print("  ##   ## ##### ######    ");lE();
    charcnt = charcnt + Serial2.print("  ######## ###  ##  ##    ");lE();
    charcnt = charcnt + Serial2.print(" ###    ## ### ###  ##    ");lE();
    charcnt = charcnt + Serial2.print("            #             ");lE();
    charcnt = charcnt + Serial2.print("                          ");lE();
    charcnt = charcnt + Serial2.print(" 8 BIT. 16MHz. LIMITLESS. ");lE();
          delay(5000);
          if(Serial1.available()){valid = 1; goto breakout;}
          
          clearLCD();
    charcnt = charcnt + Serial2.print("   __   __      _______   ");lE();
    charcnt = charcnt + Serial2.print("  I  I_I  I    I       I  ");lE();
    charcnt = charcnt + Serial2.print("  I       I    I Faire_I  ");lE();
    charcnt = charcnt + Serial2.print("  I Maker I    I   I___   ");lE(); //MFBA Banner
    charcnt = charcnt + Serial2.print("  I       I    I    ___I  ");lE();
    charcnt = charcnt + Serial2.print("  I II_II I    I   I      ");lE();
    charcnt = charcnt + Serial2.print("  I_I   I_I    I___I      ");lE();
    charcnt = charcnt + Serial2.print("   _______      _______   ");lE();
    charcnt = charcnt + Serial2.print("  I   _   I    I   _   I  ");lE();
    charcnt = charcnt + Serial2.print("  I  I_I  I    I  I_I  I  ");lE();
    charcnt = charcnt + Serial2.print("  I  Bay I     I       I  ");lE();
    charcnt = charcnt + Serial2.print("  I   _   I    I Area  I  ");lE();
    charcnt = charcnt + Serial2.print("  I  I_I   I   I   _   I  ");lE();
    charcnt = charcnt + Serial2.print("  I_______I    I__I I__I  ");lE();
          delay(5000);
          if(Serial1.available()){valid = 1; goto breakout;}
          
          clearLCD();
    charcnt = charcnt + Serial2.print("The SFE-80 is a computer  ");lE();
    charcnt = charcnt + Serial2.print("hacked together from two  ");lE();
    charcnt = charcnt + Serial2.print("Arduino microcontrollers. ");lE(); //info screen
    delay(5000);
    charcnt = charcnt + Serial2.print("- The Arduino Mega is used");lE();
    charcnt = charcnt + Serial2.print("as the central processor  ");lE();
    charcnt = charcnt + Serial2.print("of the computer and an Uno");lE();
    charcnt = charcnt + Serial2.print("is used as the keyboard   ");lE();
    charcnt = charcnt + Serial2.print("controller, converting the");lE();
    charcnt = charcnt + Serial2.print("scan codes into serial    ");lE();
    charcnt = charcnt + Serial2.print("characters.               ");lE();
    delay(5000);
    charcnt = charcnt + Serial2.print("- in 'run' mode the Mega  ");lE();
    charcnt = charcnt + Serial2.print("acts as a serial passthru ");lE();
    charcnt = charcnt + Serial2.print("between the ZIF socket and");lE();
    charcnt = charcnt + Serial2.print("the screen and keyboard.  ");lE();  
          delay(5000);
          if(Serial1.available()){valid = 1; goto breakout;}    
    }}
  
  //DIGITAL PIN CONTROL COMMAND "dWrite"
  //This command writes a value to a specified pin
  //accepts arguments for pin number (single digit) and value (0 or 1)
  
  if(cmd == "dWrite"){
    int pin = arg.charAt(1);
    if(pin<48 || pin>57){
      charcnt = charcnt + Serial2.print("invalid argument"); lE(); goto breakout;}
      pin = pin - 48;
    int bin = arg.charAt(3);
    if(bin<48 || bin>49){
      charcnt = charcnt + Serial2.print("invalid argument"); lE(); goto breakout;}
     bin = bin - 48;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, bin);
    valid = 1;
  }
  
  //ANALOG PIN CONTROL COMMAND "aRead"
  //This command reads the analog voltage on a specified pin and
  //returns it to the terminal
  
    if(cmd == "aRead"){
    int pin = arg.charAt(1);
    if(pin<48 || pin>53){
      charcnt = charcnt + Serial2.print("invalid argument"); lE(); goto breakout;}
      pin = pin - 48;
    charcnt = charcnt + Serial2.print("Value at pin A"); lE();
    charcnt = charcnt + Serial2.print(pin); lE();
    charcnt = charcnt + Serial2.print(" is reported as: "); lE();
    charcnt = charcnt + Serial2.print(analogRead(pin)); lE();
    valid = 1;
  }
  
  //ANALOG PIN CONTROL COMMAND "aWrite"
  //This command generates a PWM signal on the specified pin
  //accepts arguments for pin (3, 5, 6 or 9) and signal (0-255)
  
   if(cmd == "aWrite"){
    int pin = arg.charAt(1);
     pin = pin - 48;    
    if(pin == 3 || pin == 5 || pin == 6 || pin == 9){}
    else{ charcnt = charcnt + Serial2.print("invalid argument"); lE(); goto breakout;}
    
    int val = 257; //initialize invalid
    
    int onedcheck = arg.charAt(4); //if second digit empty it's a 1 digit number
    if(onedcheck<48 || onedcheck>53){
    int oneplace = arg.charAt(3); 
    val = oneplace-48;}
    
    int twodcheck = arg.charAt(5); //if third digit empty it's a 2 digit number
    if(twodcheck<48 || twodcheck>53){
    int oneplace = arg.charAt(4); 
    int tenplace = arg.charAt(3);
    oneplace = oneplace - 48;
    tenplace = (tenplace-48)*10;
    val = oneplace+tenplace;}
  
    
    
    else{    //else three digit number
    int oneplace = arg.charAt(5); 
    int tenplace = arg.charAt(4);
    int hunplace = arg.charAt(3);
    oneplace = oneplace - 48;
    tenplace = (tenplace-48)*10;
    hunplace = (hunplace-48)*100;
    val = oneplace+tenplace+hunplace;}
    
    if(val<0 || val>256){
      charcnt = charcnt + Serial2.print("invalid argument"); lE(); goto breakout;}
    pinMode(pin, OUTPUT);
    analogWrite(pin, val);
    valid = 1;
  }
  
  //If it isn't a known command then show off your parsing abilities
  //but don't run anything. Be rude about it.

if(!valid){
  clearLCD();
  charcnt = charcnt + Serial2.print("You want to execute the   "); lE();
  charcnt = charcnt + Serial2.print(cmd); lineFeed();
  charcnt = charcnt + Serial2.print("command"); lE();
  if(argTest == " "){
  charcnt = charcnt + Serial2.print(" with argument:   "); lE();
  charcnt = charcnt + Serial2.print(arg); lineFeed();}
  lineFeed();
  charcnt = charcnt + Serial2.print("But I'm made of Arduinos, "); lE();
  charcnt = charcnt + Serial2.print("give me a break."); lE();
}

breakout: //use Goto because you were told not to

  lineFeed();
  
  charcnt = charcnt + Serial2.print(path); lE(); //show path
  
  loop(); //restart
}

//DISPLAY DRIVER

void clearLCD(){
   delay(500);
   Serial2.write(0x7C);   //command flag
   Serial2.write((byte)0x00);   //clear command.
   linecnt=16;
   delay(10);
}

void backLCD(int i){

  for(int b = 0; b<i; b++){
   Serial2.write(0x08); //backspace
   delay(10);
  }
  
}

void lineFeed(){
  
 if(charcnt>26){ //Out of room on this line, move to next
 linecnt = linecnt - (charcnt/26);
 charcnt = charcnt - 26*(charcnt/26);}

 if(linecnt==1){ //Out of lines, clear
  linecnt=16;
  clearLCD();
 }
 
 linecnt--;
 
 int y = (linecnt*8); //y pix of line 
 
 Serial2.write(0x7C); //command flag
 Serial2.write(0x19); //y set 
 Serial2.write(y); //y pix
 
 Serial2.write(0x7C); //command flag
 Serial2.write(0x18); //x set
 Serial2.write((byte)0x00); //x pix
 
}

void lE(){ //lineEnd: keep track of line ends and advance linecnt
  
 if(charcnt>26){ //Out of room on this line, move to next
 linecnt = linecnt - (charcnt/26);
 charcnt = charcnt - 26*(charcnt/26);}

 if(linecnt==1){ //Out of lines, clear
  linecnt=16;
  clearLCD();
 }
  
}


