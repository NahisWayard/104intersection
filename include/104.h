#ifndef __104__
#define __104__

#define PX atof(argv[2])
#define PY atof(argv[3])
#define PZ atof(argv[4])

#define VX atof(argv[5])
#define VY atof(argv[6])
#define VZ atof(argv[7])

#define RAD atof(argv[8])
#define ANGLE (tan(((90 - atof(argv[8])) * M_PI) / 180)) * (tan(((90 - atof(argv[8])) * M_PI) / 180))

#endif