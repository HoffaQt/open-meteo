typedef struct city city;

typedef struct
{
    city* prev;
    city* next;
    char* name;
} city;

typedef struct
{
    city* head;
    city* tail;
} cities;