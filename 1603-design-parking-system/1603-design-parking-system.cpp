class ParkingSystem {
public:
int b,m,s;
    ParkingSystem(int big, int medium, int small) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        b=big;
        m=medium; // Intialise the  variables
        s=small;

    }
    
    bool addCar(int carType) {
      if(carType==1 && b==0 ||carType==2 && m==0||carType==3 && s==0)
      return false;
      else{
        if(carType==1 && b>0){
            b--;                   //  checking the carType
            return true;    // if the car type is in between 1,2,3
        }                // the it checks the respective space slot
             else if(carType==2 && m>0){// whether it is greater than 
            m--;                      // zero or not which there is 
                        // there is any free space is available for 
                   // that type of car or not
            return true;
        }
           else {
            s--;
            return true;
        }
      }

        
    }
};
