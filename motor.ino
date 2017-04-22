static int motor_pos = MOTOR_UNLIFT;
static int motor_state = motor_pos;

void motor_init(){
    stepper.setSpeed(MOTOR_SPEED);
    #ifdef DEBUG
      Serial.println("motor_init");
    #endif
}

void motor_execute(){
    #ifdef DEBUG
        Serial.println("motor_execute");
    #endif
    if (motor_pos != motor_state){
        if (motor_state == 1){
            stepper.step(LIFT_STEP);
            motor_pos = 1;
        }
        else{
            stepper.step(LIFT_STEP);
            motor_pos = 0;
        }
       
    }
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    #ifdef DEBUG
        Serial.print(motor_pos);
        Serial.print(" <-moto_pos  moto_state-> ");
        Serial.println(motor_state);
        Serial.println("motor execute complete");
    #endif
}

void motor_process(){
    switch(state){
        case WARM_HUMID: motor_state = 1; break;
        case WARM_DRY: motor_state = 1; break;
        case WARM_SUIT: motor_state = 1; break;
        case COOL_HUMID: motor_state = 0; break;
        case COOL_DRY: motor_state = 0; break;
        case COOL_SUIT: motor_state = 0; break;
        // case SUIT_HUMID: break;
        // case SUIT_DRY: break;
    }
    #ifdef DEBUG
        Serial.print(motor_pos);
        Serial.print(" <-moto_pos  moto_state-> ");
        Serial.println(motor_state);
    #endif
    motor_execute();
}
