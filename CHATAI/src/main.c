////////////////////////////////////////
// { PROGRAM NAME } { VERSION }
// Author: hidude562
// License: idc
// Description: Cool chatbot using markov chains and keyword recondition
////////////////////////////////////////

/*
* The comments in this file are here to guide you initially. Note that you shouldn't actually
* write comments that are pointless or obvious in your own code, write useful ones instead!
* See this for more details: https://ce-programming.github.io/toolchain/static/coding-guidelines.html
*
* Have fun!
*/

/* You probably want to keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

/* Here are some standard headers. Take a look at the toolchain for more. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphx.h>
#include <keypadc.h>
#include "gfx/gfx.h"
/* Put function prototypes here or in a header (.h) file */

/* Note: uint8_t is an unsigned integer that can range from 0-255. */
/* It performs faster than just an int, so try to use it (or int8_t) when possible */
void printText(const char *text, uint8_t x, uint8_t y);


const char* dataset[] = {"What", "is", "the", "difference", "between", "OpenCL", "and", "CUDA?", "\n", "********************", "\\n", "OpenCL", "and", "CUDA", "are", "two", "different", "programming", "models", "that", "are", "used", "for", "parallel", "computing.OpenCL", "is", "a", "general-purpose", "that", "allows", "developers", "to", "write", "parallel", "code", "that", "can", "run", "on", "any", "platform", "that", "supportsCL,", "which", "includes", "most", "modern", "operating", "systems", "and", "computer", "systems,", "including", "Windows,", "Linux,", "and", "macOS.", "It", "provides", "a", "lower-level,", "more", "flexible", "API", "that", "is", "more", "suitable", "for", "building", "large-scale", "distributed", "computing", "systems.CUDA", "is", "a", "specific", "implementation", "ofOpenCL", "that", "is", "designed", "for", "performance", "and", "scalability", "in", "devices", "with", "multiple", "GPU(s).", "It", "was", "developed", "by", "Nvidia", "and", "is", "widely", "used", "for", "scientific", "computing,", "machine", "learning,", "and.", "The", "CUDA", "API", "provides", "a", "high-level,", "more", "efficient", "way", "to", "write", "parallel", "code", "that", "can", "run", "on", "top", "of", "a", "GPU,", "while", "still", "maintaining", "the", "ability", "to", "write", "code", "that", "can", "be", "easily", "adapted", "for", "other", "parallel", "computing", "platforms.", "\\n", "********************", "\\n", "Why", "did", "my", "parent", "not", "invite", "me", "to", "their", "wedding?", "\\n", "********************", "\\n", "It", "is", "possible", "that", "your", "parent", "did", "not", "invite", "you", "to", "their", "wedding", "for", "a", "variety", "of", "reasons.", "It", "could", "be", "that", "they", "did", "not", "want", "to", "burden", "you", "with", "the", "planning", "or", "expense", "of", "the", "event,", "or", "they", "may", "not", "have", "had", "the", "time", "or", "resources", "to", "include", "you.", "Additionally,", "it", "could", "be", "that", "they", "did", "not", "feel", "comfortable", "having", "you", "attend", "due", "to", "your", "age", "or", "relationship", "with", "them.", "It", "is", "important", "to", "remember", "that", "your", "parent", "may", "have", "had", "their", "own", "reasons", "for", "not", "inviting", "you,", "and", "it", "is", "not", "your", "place", "to", "judge", "their", "choices.", "If", "you", "feel", "neglected", "or", "upset", "about", "not", "being", "invited,", "it", "is", "best", "to", "talk", "to", "them", "about", "it", "and", "express", "your", "feelings", "in", "a", "non-accusatory", "way.", "\\n", "********************", "\\n", "Fuji", "vs.", "Nikon,", "which", "is", "better?", "\\n", "********************", "\\n", "Both", "Fuji", "and", "Nikon", "are", "popular", "camera", "brands", "that", "offer", "a", "wide", "range", "of", "cameras", "for", "different", "types", "of", "photography.", "It", "really", "depends", "on", "your", "specific", "needs", "and", "preferences", "as", "to", "which", "brand", "is", "'better'", "for", "you.", "\\n", "", "\\n", "Fujifilm", "is", "known", "for", "its", "high", "image", "quality,", "especially", "in", "the", "areas", "of", "color", "accuracy", "and", "dynamic", "range.", "Many", "photographers", "also", "appreciate", "the", "company's", "focus", "on", "ergonomics", "and", "the", "overall", "user", "experience", "of", "its", "cameras.", "Additionally,", "Fujifilm", "has", "a", "loyal", "following", "among", "enthusiasts", "and", "professional", "photographers,", "thanks", "to", "its", "commitment", "to", "film", "photography", "and", "its", "high-end", "mirrorless", "cameras.", "\\n", "", "\\n", "Nikon,", "on", "the", "other", "hand,", "is", "known", "for", "its", "advanced", "autofocus", "system", "and", "image", "stabilization", "technology,", "as", "well", "as", "its", "high-end", "cameras", "and", "lenses.", "Nikon", "also", "has", "a", "wide", "selection", "of", "cameras", "and", "lenses", "to", "choose", "from,", "including", "both", "DSLR", "and", "mirrorless", "options.", "\\n", "", "\\n", "Ultimately,", "it's", "difficult", "to", "say", "which", "brand", "is", "'better'", "without", "knowing", "more", "about", "your", "specific", "needs", "and", "preferences.", "It", "might", "be", "helpful", "to", "research", "both", "brands", "further", "and", "try", "out", "a", "few", "different", "models", "before", "making", "a", "decision.", "\\n", "********************", "\\n", "How", "to", "build", "an", "arena", "for", "chatbots?", "\\n", "********************", "\\n", "Building", "an", "arena", "for", "chatbots", "can", "be", "done", "by", "following", "these", "steps:", "\\n", "", "\\n", "1.", "Define", "the", "purpose", "of", "the", "arena:", "The", "first", "step", "is"};
uint16_t datasetSize = 267;
uint16_t chatY = 5;
char* userInput = "User text bla bla bla";

// Returns only next input (not previous text)
char* markov(const char* input) {
    uint16_t   matchedWords[50];
    uint8_t    numMatchedWords = 0;

    for(uint16_t i=0; i < datasetSize; i++) {
        // TODO: Instead of using string comprae, iterate through first char, check equality, then check next
        if(input[0] == dataset[i][0]) {
            matchedWords[numMatchedWords] = i;
            numMatchedWords++;
        }
    }

    return dataset[matchedWords[0] + 1];
}


// https://stackoverflow.com/questions/8465006/how-do-i-concatenate-two-strings-in-c
// TODO: memory unoptimized and bad
char* concat(const char *s1, const char *s2)
{
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);
    char *result = malloc(len1 + len2 + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1); // +1 to copy the null-terminator
    return result;
}

char* multiMarkov(const char* input, uint8_t tokenLimit) {
    char* result   = malloc(50);
    char* previous = malloc(25);
    const char* space = " ";
    for(uint8_t i=0; i<tokenLimit; i++) {
        if(i==0)
            previous = input;
        else
            previous = markov(previous);
        if(previous[0] == 42)
            break;

        char* tmp = concat(result, space);
        tmp       = concat(result, previous);
        result    = tmp;
        free(tmp);
    }
    return result;
}

void drawText(const char text[], short x, short y, bool isAI) {
    if(isAI)
        gfx_Sprite(gpt, x, y+1);
    else
        gfx_Sprite(usr, x, y+1);

    gfx_SetColor(1);
    gfx_Rectangle(x-1,y,18,18);

    x+=20;
    short startX = x;
    uint8_t backticks = 0;
    bool inBackticks  = false;
    bool spaceWorks   = true;
    short displayLines= 0;

    gfx_SetTextFGColor(0x01);
    for(unsigned int i=0; i < strlen(text)+1; i++) {
        if(text[i]==0xA) {
            displayLines++;
            if(displayLines==2)
                startX-=21;
            x=startX;
            y+=10;
            if(inBackticks) {
                gfx_SetColor(3);
                gfx_FillRectangle(x,y,310-x,10);
            }
        } else{
            if(text[i]==96) {
                if(inBackticks)
                    backticks-=1;
                else
                    backticks+=1;

                if(backticks==3) {
                    inBackticks=true;
                    y+=1;
                    gfx_SetColor(4);
                    gfx_FillRectangle(x,y,310-x,10);
                    gfx_SetTextFGColor(0xFE);
                }
                if(backticks==0) {
                    gfx_SetTextFGColor(0x01);
                    inBackticks=false;
                }
            } else {
                if(text[i]==32) {
                    if(spaceWorks)
                        x+=8;
                } else {
                    spaceWorks=true;
                    if(!inBackticks)
                        backticks=0;
                    gfx_SetTextXY(x,y);
                    gfx_PrintChar(text[i]);
                    x+=8;
                }
            }
        }
        if(x > 300) {
            displayLines++;
            if(displayLines==2)
                startX-=21;
            x=startX;
            y+=10;

            spaceWorks=false;
            if(inBackticks) {
                gfx_SetColor(3);
                gfx_FillRectangle(x,y,310-x,10);
            }
        }
    }

    gfx_SetColor(5);
    gfx_FillRectangle(startX,y+15,310-startX,1);

    chatY = y+20;
}

void drawUserInput() {
    gfx_SetColor(5);
    gfx_Rectangle(30,225,320-30-10,13);
    gfx_PrintStringXY(userInput, 32, 228);
}

void drawReset() {
    gfx_FillScreen(255);
    gfx_SetColor(3);
    gfx_FillRectangle(0,0,20,240);

    //drawText(multiMarkov("the", 1), 32, chatY, true);
    drawText(markov("the"), 32, chatY, true);

    /* Draw test
    drawText("Hello! I am CHATai, a simple chatbot for the TI-84.", 32, chatY, true);
    drawText("Can you write python code that prints 'Hello world'", 32, chatY, false);
    drawText("Sure, I can try that:\n```python\ndef main():\n  print('Hello world!')\n\nmain()```", 32, chatY, true);
    */

    drawUserInput();
}

void runAI(const char input[]) {

}

/* This is the entry point of your program. */
/* argc and argv can be there if you need to use arguments, see the toolchain example. */
int main() {

    boot_Set48MHzMode();

    uint8_t backc = 0x19;
    os_ClrHomeFull();
    gfx_Begin(gfx_8bpp);
    //gfx_SetDrawBuffer(); Use this in a loop or something

    gfx_SetColor(255);
    gfx_SetPalette(global_palette, 256, 0);

    gfx_BlitScreen();

    drawReset();

    gfx_SwapDraw();

    while (true){ // Refer to https://ce-programming.github.io/toolchain/libraries/keypadc.html for key register info
        if(kb_On){
            break; //Stops program
        }
    }

        //A for loop that copies temp_life to lifez
    gfx_End();
    return 0;
}
