#define a 2
#define b 3
#define c 4
#define d 5

#define A 8
#define B 9
#define C 10
#define D 11
#define E 12

#define row 5
#define col 4

int * checkPressedKey(void);
int rowsList[row] = {A,B,C,D,E};
int colsList[col] = {a,b,c,d};
int * Status;
int * pre_Status;


const char* keys[5][4] = {
   {"F1","F2","#","*"},
   {"1","2","3","Up"},
   {"4","5","6","Down"},
   {"7","8","9","Esc"},
   {"<","0",">","Ent"},
};


void setup() {
  // put your setup code here, to run once:
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  
  pinMode(A,INPUT);
  pinMode(B,INPUT);
  pinMode(C,INPUT);
  pinMode(D,INPUT);
  pinMode(E,INPUT);

  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  Status = checkPressedKey();

  if (*(Status) !=-1){
    /*
      Serial.print(*(Status));
      Serial.print('|');
      Serial.println(*(Status+1));
     */

     Serial.println(keys[*(Status)][*(Status+1)]);
     pre_Status = Status;
     *(Status)=-1;
  }
  delay(250);

  
}



int * checkPressedKey(void){
    static int result[2] = {-1.-1};
    
    for(int col_i=0;col_i<col;col_i++){
        digitalWrite(colsList[col_i],HIGH);
        for (int row_i=0;row_i<row;row_i++){
              if (digitalRead(rowsList[row_i])==HIGH){
                  result[0] = row_i;
                  result[1] = col_i;
                  digitalWrite(colsList[col_i],LOW);
                  return result;
              }
        }
        digitalWrite(colsList[col_i],LOW);
       
    }

    return result;
}
