#ifndef __104__
#define __104__

#define XP atof(av[2])
#define YP atof(av[3])
#define ZP atof(av[4])

#define XV atof(av[5])
#define YV atof(av[6])
#define ZV atof(av[7])

#define PAR atof(av[8])
#define ANGLE (tan((atof(av[8]) * M_PI) / 180)) * (tan((atof(av[8]) * M_PI) / 180))
#endif