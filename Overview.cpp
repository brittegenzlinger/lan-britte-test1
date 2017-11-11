#include <iostream>
using namespace std;
//------------TEST INPUTS------------------------------

int speedInput;


//------------INPUTS-----------------------------------
int accelerometer_x; // Serial.read integer 1 ~ 5,000 3 inputs from accelerometer
int accelerometer_y;
int accelerometer_z;

int impact_sensor; // analog_read 1 - 1023

int movementSample_timbre_knob_range; //changes the range of movementSample_timbre
int movementSample_timbre_knob_min; // changes minimum of range movementSample_timbre

int movementSample_volume_knob_range; // 0-127
int movementSample_volume_knob_min; // 0-127

int impactSample_timbre_knob_range; // 0-127
int impactSample_timbre_knob_min; // 0-127

int impactSample_volume_knob_range; // 0-127
int impactSample_volume_knob_min; //  min + range = max volume


//------------OUTPUTS----------------------------------------------
char movementSample_timbre; // range: 0 - 127 midi CC output 0
char movementSample_volume;
char impactSample_timbre;
char impactSample_volume;

void readInputs(){
  cout << "enter Speed";
  cin >> speedInput;

  cout << "enter Impact";
  cin >> impact_sensor;

  cout << "enter MTR(movement timbre range)(1-4)";
  cin >> movementSample_timbre_knob_range;

  cout << "enter MTM(movement timbre minimum)(1-4)";
  cin >> movementSample_timbre_knob_min;

  cout << "enter ITR(impact timbre range)(1-4)";
  cin >> impactSample_timbre_knob_range;

  cout << "enter ITM(impact timbre minimum)(1-4)";
  cin >> impactSample_timbre_knob_min;

  cout << "enter IVR(impact volume range)(1-4)";
  cin >> impactSample_volume_knob_range;

  cout << "enter IVM(impact volume minimum)(1-4)";
  cin >> impactSample_volume_knob_min;

  cout << "enter MVR(movement volume range)(1-4)";
  cin >> movementSample_volume_knob_range;

  cout << "enter MVM(movement volume minimum)(1-4)";
  cin >> movementSample_volume_knob_min;

}

char createOutput(char speed, char min, char range){
  char value;
  float percentSpeed;
  percentSpeed = (speed / 127);
  value = char(percentSpeed * range) + min;


  return value;
}

void process(){

  char speed = speedInput; //use acceleration formula, get speed from accelerations

  movementSample_timbre = createOutput(speed, movementSample_timbre_knob_min, movementSample_timbre_knob_range);
  movementSample_volume = createOutput(speed, movementSample_volume_knob_min, movementSample_volume_knob_range);
  impactSample_timbre =  createOutput(impact_sensor, impactSample_timbre_knob_min, impactSample_timbre_knob_range);
  impactSample_volume = createOutput(impact_sensor, impactSample_volume_knob_min, impactSample_volume_knob_range);

}



void sendSignal(){

}

void testFunc(){

cout << int(movementSample_timbre);
cout <<" \n";
cout << int(movementSample_volume);
cout <<" \n";
cout << int(impactSample_timbre);
cout <<" \n";
cout << int(impactSample_volume);
cout <<" \n";



}


int main(){
  readInputs();
  process();
  testFunc();
  sendSignal();

  //return 0;
}
