// Deklarasi Variable sensor
int sensor1 = A0;
int sensor2 = A1;
int sensor3 = A2;
int sensor4 = A3;
int sensor5 = A4;
int sensor6 = A5;
int baca_sensor[6];

// untuk variable motor 
int pinEnable =4; // harus diset HIGH apabila akan di aktifkan 
int pinEnable2 = 2;
//Motor Kiri
int motor_kiri1 = 5;//input motor driver 1 L293D
int motor_kiri2 = 6;//input motor driver 2 L293D
//Motor Kanan
int motor_kanan1 = 3;//input motor driver 3 L293D
int motor_kanan2 = 11;

void setup()
{
  //pinmode input sensor
  pinMode(sensor1, INPUT);
   pinMode(sensor2, INPUT);
   pinMode(sensor3, INPUT);
   pinMode(sensor4, INPUT);
   pinMode(sensor5, INPUT);
   pinMode(sensor6, INPUT);
   
  //PIN mode output motor
  pinMode(pinEnable, OUTPUT);
  pinMode(pinEnable2, OUTPUT);
  pinMode(motor_kiri1, OUTPUT);
  pinMode(motor_kiri2, OUTPUT);
  pinMode(motor_kanan1, OUTPUT);
  pinMode(motor_kanan2, OUTPUT);
  
  Serial.begin(9600);
}

void readsensor() { //Fungsi Untuk membaca sensor kemudian menyimpan Array
	baca_sensor[0] = analogRead(sensor1);
  baca_sensor[1] = analogRead(sensor2);
  baca_sensor[2] = analogRead(sensor3);
  baca_sensor[3] = analogRead(sensor4);
  baca_sensor[4] = analogRead(sensor5);
  baca_sensor[5] = analogRead(sensor6);
  
  Serial.println(baca_sensor[0]);
}
  void loop()
{
    
    readsensor();
    //Sensor 1 dan 2 mendeteksi gelap : Motor kanan aktif, Motor kiri mati
    if (baca_sensor[0] < 34 && baca_sensor[1] < 34 && baca_sensor[2] > 34 && baca_sensor[3] > 34 && baca_sensor[4] > 34 && baca_sensor[5] > 34){
        digitalWrite(pinEnable, HIGH);
        digitalWrite(motor_kiri1, LOW);
        digitalWrite(motor_kiri2, LOW);
        
        digitalWrite(pinEnable2, HIGH);
        digitalWrite(motor_kanan1, HIGH);
        digitalWrite(motor_kanan2, LOW);
    }
    //Sensor 3 dan 4 mendeteksi gelap : Kedua motor aktif
    else if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && baca_sensor[2] < 34 && baca_sensor[3] < 34 && baca_sensor[4] > 34 && baca_sensor[5] > 34){
        digitalWrite(pinEnable, HIGH);
        digitalWrite(motor_kiri1, HIGH);
        digitalWrite(motor_kiri2, LOW);
        
        digitalWrite(pinEnable2, HIGH);
        digitalWrite(motor_kanan1, HIGH);
        digitalWrite(motor_kanan2, LOW);
    }
    //Sensor 5 dan 6 mendeteksi gelap : Motor kanan mati, motor kiri aktif
    else if (baca_sensor[0] > 34 && baca_sensor[1] > 34 && baca_sensor[2] > 34 && baca_sensor[3] > 34 && baca_sensor[4] < 34 && baca_sensor[5] < 34){
        digitalWrite(pinEnable, HIGH);
        digitalWrite(motor_kiri1, HIGH);
        digitalWrite(motor_kiri2, LOW);
        
        digitalWrite(pinEnable2, HIGH);
        digitalWrite(motor_kanan1, LOW);
        digitalWrite(motor_kanan2, LOW);
    }
    //Semua sensor tidak mendeteksi gelap : Kedua motor mati
    else {
        digitalWrite(pinEnable, HIGH);
        digitalWrite(motor_kiri1, LOW);
        digitalWrite(motor_kiri2, LOW);
        
        digitalWrite(pinEnable2, HIGH);
        digitalWrite(motor_kanan1, LOW);
        digitalWrite(motor_kanan2, LOW);
    }
}