/*  CSC A48 - Winter 2020
*
*   Exercise 6 - The Resistant Strain
*
*   Please read the comments below carefully, they
*  describe your task in detail. Any clarifications
*  and corrections will be posted to Piazza so please
*  keep an eye on the forum!
*
*  Starter code: Joe Armitage & William Song, 2020
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TISSUE_SIZE (10)

typedef enum tissueType
{
    _ = '_',  // Uninfected cell
    I = 'I',  // Infected cell
    S = 'S',  // Good bacterium: Sakinacoccus
    C = 'C',  // Good bacterium: Charlestridium tetani
} TissueType;

typedef struct cell
{
    TissueType type;  // Indicates if good bacterium, infected cell or uninfected cell
    int health;  // For good bacteria: the multiple the range is extended by, for infected cells,
                 // number of lives
} Cell;

typedef Cell Tissue[TISSUE_SIZE][TISSUE_SIZE];  // A nice name for a 2D Cell array -> Tissue

/**
 * CRUNCHY: Use this helper helper function to implement Charles AND Sakina
 * HINT: I would implement numberOfCharlesInRange like this:
 *      Pattern charles_patterns[4] = {{2, 0}, {0, 2}, {-2, 0}, {0, -2}};
 *      return numberOfBacteriaInRange(tissue_sample, x, y, charles_patterns, 4, C);
 */
typedef int Pattern[2];

int numberOfBacteriaInRange(Tissue tissue, int x, int y, Pattern pattern[], int num_patterns,
                            TissueType type)
{
    /** CRUNCHIER: do this without looping over all the cells (again) (attacks are symmetric!) */
    int counter = 0;

    return counter;
}

/**
 * Return the number of Charlestridium tetani within tissue_sample that can attack position x, y.
 *
 * Legal attacks are limited to the pattern (where X is a legal attack and C is the bacterium):
 *      _ _ X _ _
 *      _ _ _ _ _
 *      X _ C _ X
 *      _ _ _ _ _
 *      _ _ X _ _
 * where each Charlestridium tetani can attack in any one direction in this pattern for a certain
 * number of attacks. For example, if one had 2 health, its pattern would be limited to:
 *      _ _ _ _ X _ _ _ _
 *      _ _ _ _ _ _ _ _ _
 *      _ _ _ _ X _ _ _ _
 *      _ _ _ _ _ _ _ _ _
 *      X _ X _ C _ X _ X
 *      _ _ _ _ _ _ _ _ _
 *      _ _ _ _ X _ _ _ _
 *      _ _ _ _ _ _ _ _ _
 *      _ _ _ _ X _ _ _ _
 *
 * INPUT:
 *  tissue_sample:
 *      - an array of arrays of Cells with dimensions TISSUE_SIZE * TISSUE_SIZE
 *      - gives positions of each bacterium and each infected cell
 *      - each cell can only contain one of the following types:
 *          - `I`: Infected Cell
 *          - `L`: A Charlestridium tetani bacterium
 *          - `S`: A Sakinacoccus bacterium
 *          - `_`: An uninfected cell (bacteria will ignore these)
 *  x:  the row coordinate (starting at 0) of the cell (within tissue_sample) to be checked.
 *  y:  the column coordinate (starting at 0) of the cell (within tissue_sample) to be checked.
 *
 * RETURN: the number of Charlestridium tetani that can make a legal attack to position x, y
 */
int numberOfCharlesInRange(Tissue tissue_sample, int x, int y)
{
    /** TODO: implement this function, satisfying the description above. */

    //int k = tissue_sample[x][y].health;
    int l=0;
    int count2=0;
    int total =0;
    
    for(int row = 0; row < TISSUE_SIZE; row++){
        for(int colum = 0; colum < TISSUE_SIZE; colum++){
            if(tissue_sample[row][colum].type == 'C'){
                for(int incre = (tissue_sample[row][colum].health*2); incre >= -(tissue_sample[row][colum].health*2); incre= incre - 2){
                    if(((row + incre == x) && (colum == y))){
                        l++;
                    }
                    else if(((row == x) && (colum + incre == y))){
                        count2++;
                    }
                }
            }
        }
    }
    total = count + count2;
    return total;
}

/**
 * Return the number of Sakinacoccus within tissue_sample that can attack position x, y.
 *
 * Legal attacks are limited to the pattern (where X is a legal attack and S is the bacterium):
 *      _ _ _ _ _
 *      _ X _ X _
 *      _ _ S _ _
 *      _ X _ X _
 *      _ _ _ _ _
 * where each Sakinacoccus can attack in any one direction in this pattern for a certain
 * number of attacks. For example, if one had 2 health, its pattern would be limited to:
 *      X _ _ _ X
 *      _ X _ X _
 *      _ _ S _ _
 *      _ X _ X _
 *      X _ _ _ X
 *
 * INPUT:
 *  tissue_sample:
 *      - an array of arrays of Cells with dimensions TISSUE_SIZE * TISSUE_SIZE
 *      - gives positions of each bacterium and each infected cell
 *      - each cell can only contain one of the following types:
 *          - `I`: Infected Cell
 *          - `L`: A Charlestridium tetani bacterium
 *          - `S`: A Sakinacoccus bacterium
 *          - `_`: An uninfected cell (bacteria will ignore these)
 *  x:  the row coordinate (starting at 0) of the cell (within tissue_sample) to be checked.
 *  y:  the column coordinate (starting at 0) of the cell (within tissue_sample) to be checked.
 *
 * RETURN: the number of Sakinacoccus that can make a legal attack to position x, y
 */
int numberOfSakinaInRange(Tissue tissue_sample, int x, int y)
{
    /** TODO: implement this function, satisfying the description above. */

    int k = tissue_sample[x][y].health;
    int count=0;
    int count1=0;
    int total =0;
    
    for(int row = 0; row < TISSUE_SIZE; row++){
        for(int colum = 0; colum < TISSUE_SIZE; colum++){
            if(tissue_sample[row][colum].type == 'S'){
                for(int a = -((k*2)+1); a <= ((k*2)+1); a++){
                    for(int b =-((k*2)+1); b <= ((k*2)+1); b++){
                        if(a == b){
                            if((row + a == x && colum + b == y) || (row + a == x && colum - b == y)){
                                count++;
                            }
                        }
                    }
                }
            }
        }
    }
    total = count + count1;
    return total;
}

/**
 * Computes the percentage of infected cells in the given tissue sample which can be killed
 * by Sakinacoccus or Charlestridium tetani bacteria in the sample and updates the tissue sample to
 * the state after the attacks.
 *
 * INPUT:
 *  tissue_sample:
 *      - an array of arrays of Cells with dimensions TISSUE_SIZE * TISSUE_SIZE
 *      - gives positions of each bacterium and each infected cell
 *      - each cell can only contain one of the following types:
 *          - `I`: Infected Cell
 *          - `C`: A Charlestridium tetani bacterium
 *          - `S`: A Sakinacoccus bacterium
 *          - `_`: An uninfected cell (bacteria will ignore these)
 *      - REQ: there is at least one infected cell
 *
 * OUTPUT:
 *  tissue_sample: - mutated such that:
 *      - All `I` cells have their health reduced by the number of good bacteria that can attack.
 *      - Any `I` cell whose health drops to <= 0 is replaced by a `_` cell, with 0 health.
 *
 * RETURN:
 *  The percentage of infected cells that are killed by the good bacteria (Sakinacoccus and
 * Charlestridium tetani).
 */
double testBacteria(Tissue tissue_sample)
{
    /**
     * TODO: Implement this function, satisfying the description above.
     *
     * CRUNCHY: Can you do this without using a loop in a loop?
     *              -> Think about how this 2D array is stored in memory...
     */

    double total_infected = 0;
    double can_be_killed = 0;

    for(int x=0; x <TISSUE_SIZE; x++){
        for(int y=0; y <TISSUE_SIZE; y++){
            if(tissue_sample[x][y].type == 'I'){
                total_infected++;
                if((numberOfCharlesInRange(tissue_sample,x,y) + 
                 numberOfSakinaInRange(tissue_sample,x,y)) >= tissue_sample[x][y].health)
                {
                    can_be_killed ++;
                    tissue_sample[x][y].health = 0;
                    tissue_sample[x][y].type = '_';
                }
            }
        }
    }
    printf("Total infected %f\n", total_infected);
    printf("Can be Killed %f\n", can_be_killed);
    return ((can_be_killed/total_infected)*100);
}

/**
 * Prints the tissue sample in a human readable format.
 *
 * INPUT:
 *  tissue_sample:
 *      - an array of arrays of Cells with dimensions TISSUE_SIZE * TISSUE_SIZE
 *      - gives positions of each bacterium and each infected cell
 *      - each cell can only contain one of the following types:
 *          - `I`: Infected Cell
 *          - `L`: A Charlestridium tetani bacterium
 *          - `S`: A Sakinacoccus bacterium
 *          - `_`: An uninfected cell (bacteria will ignore these)
 *
 * NOTE: The displayed indices do not match the implementation.
 * That is, they start at 1 (when we know array indices start at 0).
 * This is more obvious for the column indices, which are A - J.
 */
void printTissueSample(Tissue tissue_sample)
{
    printf("   A B C D E F G H I J\n");
    for (int x = 0; x < TISSUE_SIZE; x++)
    {
        printf("%2d ", x + 1);
        for (int y = 0; y < TISSUE_SIZE; y++) printf("%c ", tissue_sample[x][y].type);
        printf("\n");
    }
}

// We NEED this compiler directive to test your code with our own main(). Don't break it.
#ifndef __TESTING  // this compiler directive
int main()
{
    // Please note that these are JUST EXAMPLES! You will be tested on a wide range of data.
     printf("====Empty's Sample====\n");
    Tissue empty = {
        {{_, 0}, {_, 0}, {_, 0}, {I, 1}, {_, 0}},
        {{I, 1}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}}};
    printTissueSample(empty);
    printf("Calculated: Killed %06.2f%% of bacteria\n", testBacteria(empty));
    printf("  Expected: Killed 000.00%% of bacteria\n");
    printTissueSample(empty);

    
    printf("====Jackson3's Sample====\n");
    Tissue jackson3_sample = {
        {{I, 1}, {_, 0}, {_, 0}, {_, 0}, {I, 1}},
        {{_, 0}, {I, 1}, {_, 0}, {I, 1}, {_, 0}},
        {{_, 0}, {_, 0}, {S, 2}, {_, 0}, {_, 0}},
        {{_, 0}, {I, 1}, {_, 0}, {I, 1}, {_, 0}},
        {{I, 1}, {_, 0}, {_, 0}, {_, 0}, {I, 1}}};
    printTissueSample(jackson3_sample);
    printf("Calculated: Killed %06.2f%% of bacteria\n", testBacteria(jackson3_sample));
    printf("  Expected: Killed 0100.00%% of bacteria\n");
    printTissueSample(jackson3_sample);

    printf("====Jackson2's Sample====\n");
    Tissue jackson2_sample = {
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {I, 1}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {I, 1}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{I, 1}, {_, 0}, {I, 1}, {_, 0}, {C, 2}, {_, 0}, {I, 1}, {_, 0}, {I, 1}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {I, 1}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {I, 1}, {_, 0}, {_, 0}, {_, 0}, {_, 0}}};
    printTissueSample(jackson2_sample);
    printf("Calculated: Killed %06.2f%% of bacteria\n", testBacteria(jackson2_sample));
    printf("  Expected: Killed 0100.00%% of bacteria\n");
    printTissueSample(jackson2_sample);
   
    printf("====Jackson's Sample====\n");
    Tissue jackson_sample = {
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {C, 1}, {_, 0}, {I, 1}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {I, 3}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {I, 2}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {S, 2}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}}};
    printTissueSample(jackson_sample);
    printf("Calculated: Killed %06.2f%% of bacteria\n", testBacteria(jackson_sample));
    printf("  Expected: Killed 066.67%% of bacteria\n");
    printTissueSample(jackson_sample);

    // Feel free to add your own examples/tests here
    printf("====Silviu's Sample====\n");
    Tissue silviu_sample = {
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {I, 1}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {I, 1}, {_, 0}, {_, 0}, {I, 1}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {I, 1}},
        {{_, 0}, {_, 0}, {_, 0}, {I, 1}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {I, 1}, {S, 2}},
        {{_, 0}, {_, 0}, {_, 0}, {I, 1}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {C, 3}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {C, 2}, {_, 0}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {I, 1}, {I, 1}, {I, 1}},
        {{_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {_, 0}, {I, 1}, {_, 0}}};
    printTissueSample(silviu_sample);
    printf("Calculated: Killed %06.2f%% of bacteria\n", testBacteria(silviu_sample));
    printf("  Expected: Killed 036.36%% of bacteria\n");
    printTissueSample(silviu_sample);
    

}
#endif  // and this compiler directive