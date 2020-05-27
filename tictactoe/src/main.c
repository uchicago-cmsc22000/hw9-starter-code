#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>

#include "game.h"
#include "strategy.h"


int main(int argc, char *argv[])
{
    int opt;
    int verbosity = 0, num_games_opt = 1000;
    char *strategyX = NULL, *strategyO = NULL;

    while ((opt = getopt(argc, argv, "X:O:n:vh")) != -1)
        switch (opt)
        {
        case 'X':
            strategyX = strdup(optarg);
            break;
        case 'O':
            strategyO = strdup(optarg);
            break;
        case 'n':
            num_games_opt = strtol(optarg, NULL, 10);
            break;
        case 'v':
            verbosity++;
            break;
        case 'h':
            printf("Usage: tictactoe -X STRATEGY -O STRATEGY -n NUM_GAMES [-v|-vv|-vvv]\n");
            exit(0);
            break;
        default:
            printf("ERROR: Unknown option -%c\n", opt);
            exit(-1);
        }


    /* Validate parameters */

    if(strategyX == NULL || strategyO == NULL)
    {
        printf("You must specify strategies with the -X and -O options\n");
        exit(-1);
    }

    strategy_func stratX, stratO;

    stratX = get_strategy(strategyX);
    if(stratX == NULL)
    {
        printf("Unknown strategy: %s\n", strategyX);
        exit(-1);
    }

    stratO = get_strategy(strategyO);
    if(stratO == NULL)
    {
        printf("Unknown strategy: %s\n", strategyO);
        exit(-1);
    }

    if(num_games_opt <= 0)
    {
        printf("ERROR: Invalid number of games %s\n", optarg);
        exit(-1);
    }
    unsigned int num_games = (unsigned int) num_games_opt;


    /* Initialize random seed */
    srand(time(NULL)); 

    /* Play the games and tally up the winners and ties */
    game_t g;
    unsigned int wins_X = 0;
    unsigned int wins_O = 0;
    unsigned int ties = 0;

    unsigned int num_moves_X = 0;
    unsigned int num_moves_O = 0;

    for(unsigned int i=0; i < num_games; i++)
    {
        player_t winner;

        winner = game_play(&g, stratX, stratO);

        if(winner == X)
        {
            wins_X++;
            num_moves_X += g.num_moves;
        }
        else if(winner == O)
        {
            wins_O++;
            num_moves_O += g.num_moves;
        }
        else if(winner == NONE)
        {
            ties++;
        }
    }

    assert(wins_X + wins_O + ties == num_games);

    /* Print results */
    float pct_X, pct_O, pct_ties, avg_mov_X, avg_mov_O;

    pct_X = (wins_X * 100.0) / num_games;
    pct_O = (wins_O * 100.0) / num_games;
    pct_ties = (ties * 100.0) / num_games;

    avg_mov_X = num_moves_X / (float) wins_X;
    avg_mov_O = num_moves_O / (float) wins_O;

    printf("X wins: %.2f%% (avg moves to win: %.2f)\n", pct_X, avg_mov_X);
    printf("O wins: %.2f%% (avg moves to win: %.2f)\n", pct_O, avg_mov_O);
    printf("Ties: %.2f%%\n", pct_ties);
}
