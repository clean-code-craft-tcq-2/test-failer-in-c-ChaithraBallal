#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;
#define TEMPTHRESHOLD 150

int networkAlert(float celcius) 
{
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    if(celcius <= TEMPTHRESHOLD )
    {
         return 200;
    }
    else
    {
        return 500;
    }
   
}

float alertInCelcius_main(float farenheit) 
{
    float celcius = (farenheit - 32) * 5 / 9;
    return celcius;
}
/*Code under test*/
void alertInCelcius(float farenheit) 
{
    float celcius = alertInCelcius_main(farenheit);
    int returnCode = networkAlert(celcius);
    if (returnCode != 200) 
    {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}
/*Testing environment*/
int main() 
{
    alertInCelcius(303.6);
    alertInCelcius(650);
    alertInCelcius(400.5);
    assert(alertInCelcius_main(400.5) == 204.7f);
    printf("%d alerts failed.\n", alertFailureCount);
    assert(alertFailureCount == 3);
    printf("All is well (maybe!)\n");
    return 0;
}
