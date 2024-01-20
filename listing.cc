#include <cstdio>
#include <string>
#include <queue> // Include queue for storing error messages

using namespace std;

#include "listing.h"

static int lineNumber; // Static variable for keeping track of line numbers
static int totalErrors = 0; // Static variable to count the total number of errors
static int lexicalErrors = 0;
static int syntaxErrors = 0;
static int semanticErrors = 0;
static queue<string> errorQueue; // Queue to store error messages

void displayErrors();

// Function to initialize and print the first line number
void firstLine()
{
    lineNumber = 1; // Initialize line number to 1
    printf("\n%4d  ", lineNumber); // Print the line number with formatting
}

// Function to print the next line number and handle errors
void nextLine()
{
    displayErrors(); // Display any errors that occurred on the current line
    lineNumber++; // Increment the line number
    printf("%4d  ", lineNumber); // Print the line number with formatting
}

// Function to handle the last line of the listing
int lastLine()
{
    printf("\r");
    displayErrors(); // Display any errors for the last line

    if (totalErrors == 0)
    {
        printf("Compiled Successfully\n");
    }
    else
    {
        printf("Lexical Errors %d\n", lexicalErrors);
        printf("Syntax Errors %d\n", syntaxErrors);
        printf("Semantic Errors %d\n", semanticErrors);
    }

    return lineNumber;
}

// Function to append an error message to the current error
void appendError(ErrorCategories errorCategory, string message)
{
    string messages[] = { "Lexical Error, Invalid Character ", "",
        "Semantic Error, ", "Semantic Error, Duplicate ",
        "Semantic Error, Undeclared " };

    // Count errors based on category
    switch (errorCategory)
    {
        case LEXICAL:
            lexicalErrors++;
            break;
        case SYNTAX:
            syntaxErrors++;
            break;
        case GENERAL_SEMANTIC:
            semanticErrors++;
            break;
    }

    // Concatenate error category message with the custom message
    errorQueue.push(messages[errorCategory] + message);
    totalErrors++; // Increment total error count
}

// Function to display all the error messages that have occurred on the previous line
void displayErrors()
{
    while (!errorQueue.empty())
    {
        printf("%s\n", errorQueue.front().c_str());
        errorQueue.pop();
    }
}
