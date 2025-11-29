#include <stdio.h>
#include <stdbool.h>

void calculateFuel(int fuel, int consumption, int recharge, int solarBonus, int planet, int totalPlanets){
    //-fixed amt of fuel consumed at each planet stop
    //-some fuel is regenrated due to gravity/reduced energy use
    //-after every 4th planetry stop, solar recharge occurs,increasing fuel reserves
    //-base case: fuel is zero/exhausted OR all planets visited
    //-recursie case handles fuel adjustment for each subsequent planet
    //print "Planet X: Fuel Remaining = Y", and
//determines whether the spacecraft can complete its journey.
   //planet = 0, totalPlanets = 8, fuel = 8000, consumption = 2000
//solarbonus = 1000
//base case
if(fuel < consumption && planet < totalPlanets){
    printf("not enough fuel\n");
    return;
} else if(planet > totalPlanets){
    printf("journey completed\n");
 return;
}

int gravCharge = 500;
   
   fuel = fuel - consumption;
   if((planet == 4 || planet == 8)){
    recharge = 1;
    fuel = fuel + solarBonus;
   } else if(planet == 2 || planet == 5) {
    recharge = 1;
    fuel = fuel + gravCharge;
   } else {
    recharge = 0;
   }
   printf("Planet %d: Fuel Remaining: %d\n", planet, fuel);

   calculateFuel(fuel,consumption,recharge,solarBonus,planet+1,totalPlanets);


}



int main(){



    return 0;
}