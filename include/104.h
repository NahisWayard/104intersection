#ifndef __104__
#define __104__

#define PX atof(av[2])
#define PY atof(av[3])
#define PZ atof(av[4])

#define VX atof(av[5])
#define VY atof(av[6])
#define VZ atof(av[7])

#define RAD atof(av[8])
#define ANGLE (tan(((90 - atof(av[8])) * M_PI) / 180)) * (tan(((90 - atof(av[8])) * M_PI) / 180))

#endif