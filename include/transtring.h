#ifndef PIKOSTUDIOS_TRANSTRING_H
#define PIKOSTUDIOS_TRANSTRING_H

#include <stdlib.h>
#include <string.h>
#define _TS(str) ts_find(str)
/*

```c
...

ts_set_language(LANGUAGE_SPANISH);
const char* msg = _TS("Hello, World!");
printf("%s\n", msg); // Hola, Mundo! 

*/

static char* ts_hashmap;
static size_t ts_hashmap_size;
static int ts_current_language;

void ts_set_language(int language);

void* ts_realloc(void* ptr, size_t size); // Internal memory realloc'er
int ts_hash(const char* str); // Internal hasing function
void ts_initialize_hashmap(size_t starting_size);


const char* ts_find(const char* str);

#ifdef TRANSTRING_IMPLEMENTION

void ts_set_language(int language)
{
    ts_current_language = language;
}

void* ts_realloc(void* ptr, size_t size)
{
    void* buffer = realloc(ptr, size);
    if (buffer == NULL)
    {
        free(ptr);
        return NULL;
    }

    return buffer
}

void ts_hash(const char* str)
{
    int len = strlen(str);

    return (((str[i] + 1) * str[i]) + len) % ts_hashmap_size;
}

void ts_initialize_hasmap(size_t starting_size)
{

}

#endif //TRANSTRING_IMPLEMENTION

#endif //PIKOSTUDIOS_TRANSTRING_H