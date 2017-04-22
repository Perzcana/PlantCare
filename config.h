//----temp-----
#define TEMP_MIN 25
#define TEMP_MAX 30
#define HUMIDITY_MIN 60
#define HUMIDITY_MAX 80
//----sensor------
#define DHTPIN 5
#define DHTTYPE DHT11
#define DHT_POWER_PIN 6
#define DHT_INIT_INTERVAL 1111
//----motor------
#define MOTOR_LIFTED 1
#define MOTOR_UNLIFT 0
#define MOTOR_SPEED 480
#define stepsPerRevolution 32
#define revolutionPerRound 64
#define feedPerRound 60
#define LIFT_DISTANCE 100 //mm
float FEED_ROUND = (float)LIFT_DISTANCE/feedPerRound;
const int LIFT_STEP = stepsPerRevolution*revolutionPerRound*FEED_ROUND;
//----energy----
#define CALL_TIMES 75
#define TIME_PER_SLEEP 9
// 0=16ms, 1=32ms,2=64ms,3=128ms,4=250ms,5=500ms
// 6=1 sec,7=2 sec, 8=4 sec, 9= 8sec
//----const state-----
#define WARM_HUMID 1
#define WARM_DRY 2
#define WARM_SUIT 3
#define COOL_HUMID 4
#define COOL_DRY 5
#define COOL_SUIT 6
#define SUIT_HUMID 7
#define SUIT_DRY 8
#define SUIT 0
