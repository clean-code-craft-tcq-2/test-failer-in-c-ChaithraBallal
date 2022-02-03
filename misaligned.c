#include <stdio.h>
#include <assert.h>
#include <string.h>

 const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
 const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

 typedef struct
 {
     int PairNumber;
     char majorColor[8];
     char minorColor[8];     
 }ColorData;

/*Code under test*/
ColorData PrintColorMap_test(int majorID, int minorID)
{
    ColorData colormapping;
     /*Copy the strings to their actual structure*/
     colormapping.PairNumber = (majorID * 5) + minorID + 1 ;
     strcpy(colormapping.majorColor, majorColor[majorID]); 
     strcpy(colormapping.minorColor, minorColor[minorID]);
     printf("%d | %s | %s\n", colormapping.PairNumber, majorColor[majorID], minorColor[minorID]);
     return colormapping;    
}

int printColorMap() 
{  
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) 
    {
        for(j = 0; j < 5; j++) 
        {
           PrintColorMap_test(i,j);
        }
    }
    return i * j;
}

/* Testing environment */
int main() 
{
    int result = printColorMap();
    int MajorcolorIndex = 2;
    int MinorcolorIndex = 3;
    assert(result == 25);
    ColorData colormap;
    colormap = PrintColorMap_test(MajorcolorIndex,MinorcolorIndex);
    assert(colormap.PairNumber == 14);
    assert(strcmp(colormap.minorColor,"Brown") == 0);
    assert(strcmp(colormap.majorColor,"Black") == 0);
    printf("All is well (maybe!)\n");
    return 0;
}
