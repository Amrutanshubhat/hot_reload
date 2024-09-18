#include "main.h"

void (*update_plug)(void) = NULL;

void reload_hot() {
	if (hotplug != NULL) {
		dlclose(hotplug);
	}
	// load .so file
	hotplug = dlopen(hot_path, RTLD_NOW);
	if (hotplug == NULL) {
		printf("Error: %s\n", dlerror());
	}
	// grapb fuction symbol from .so
	update_plug = dlsym(hotplug, "hot_update");
	if (update_plug == NULL) {
		printf("Error: %s\n", dlerror());
	}
}

int main() {
	reload_hot();

	InitWindow(w_width, w_height, "<()>");
	while(!WindowShouldClose()) {
		if (IsKeyPressed(KEY_R)) {
			reload_hot();
		}
		update_plug();
	}
	CloseWindow();
}
