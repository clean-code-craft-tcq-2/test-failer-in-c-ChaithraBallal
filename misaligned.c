#include <stdio.h>
#include <assert.h>
#include <string.h>

 const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
 const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

 typedef struct
 {
     int PairNumber;
     char majorColor[5];
     char minorColor[5];     
 }ColorData;

int printColorMap() 
{  
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) 
    {
        for(j = 0; j < 5; j++) 
        {
           printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

ColorData TestPrintColorData(int Pairnum, const char* Major_color, const char* Minor_color)
{
     ColorData colormapping;
     /*Copy the strings to their actual structure*/
     colormapping.PairNumber = Pairnum;
     strcpy(colormapping.majorColor,Major_color); 
     strcpy(colormapping.minorColor,Minor_color);
     return colormapping;    
}
/* Testing environment */
int main() 
{
    int result = printColorMap();
    int MajorcolorIndex = 2;
    int MinorcolorIndex = 4;
    ColorData colormap;
    assert(result == 25);
    colormap = TestPrintColorData(MajorcolorIndex*5 + MinorcolorIndex , majorColor[MajorcolorIndex], minorColor[MinorcolorIndex] );
    assert(colormap.PairNumber == 14);
    assert(strcmp(colormap.majorColor,"Black") == 0);
    assert(strcmp(colormap.minorColor,"Brown") == 0);
    printf("All is well (maybe!)\n");
    return 0;
}
