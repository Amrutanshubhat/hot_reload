#include <time.h>
#include <stdlib.h>
#include "raylib.h"

void hot_update(){

	srand(time(NULL));
	Color rnd = GetColor(rand()%(0xFFFFFFFF));
	/*Color rnd = VIOLET;*/
	BeginDrawing();
	ClearBackground(rnd);
	EndDrawing();
}
