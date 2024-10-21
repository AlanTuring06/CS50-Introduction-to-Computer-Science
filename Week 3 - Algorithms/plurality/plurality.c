#include <stdio.h>
#include <string.h>
#include <stdbool.h>  // Include this for bool, true, and false

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    char *name;  // Change string to char* for standard C
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(char *name);
void print_winner(void);

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count;
    printf("Number of voters: ");
    scanf("%d", &voter_count);  // Use scanf to get the number of voters

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        char name[100];  // Assuming max name length of 99 characters
        printf("Vote: ");
        scanf("%99s", name);  // Use scanf to get the voter's name

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(char *name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Check for Winner of the votes
    int max = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max)  // Update to only set max when strictly greater
        {
            max = candidates[i].votes;
        }
    }
    // Name of the winner
    for (int i = 0; i < candidate_count; i++)
    {
        if (max == candidates[i].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}