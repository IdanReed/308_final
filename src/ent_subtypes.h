#ifndef __ENT_SUBTYPES__
#define __ENT_SUBTYPES__

#define OPTIONS_MAX 10

typedef struct Ent_house Sub_house;

typedef struct Ent_house{
  char * entry_message;
  int enemy_health;

  int act_option_cnt;
  char * options[OPTIONS_MAX];
} Ent_house;


#endif
