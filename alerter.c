#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;
#define TEMPTHRESHOLD 150

int networkAlertStub(float celcius) 
{
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if(celcius <= TEMPTHRESHOLD )
    {
         return 200;
    }
    else
    {
        return 500;
    }
   
}

float alertInCelcius_test(float farenheit_test) 
{
    float celcius_test = (farenheit_test - 32) * 5 / 9;
    return celcius_test;
}

void alertInCelcius(float farenheit) 
{
    float celcius = alertInCelcius_test(farenheit);
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) 
    {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() 
{
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    alertInCelcius(650);
    printf("%d alerts failed.\n", alertFailureCount);
    assert(alertFailureCount == 1);
    printf("All is well (maybe!)\n");
    return 0;
}
