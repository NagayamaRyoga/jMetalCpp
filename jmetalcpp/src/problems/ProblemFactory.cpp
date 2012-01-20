/**
 * @file ProblemFactory.cpp
 * @author Esteban L�pez
 * @version 1.0
 * @date 18 January 2012
 */


#include <ProblemFactory.h>


/**
 * Problem factory
 * @param name : Name of the problem
 */
Problem * ProblemFactory::getProblem(char * name) {
  return getProblem(name, 0, NULL);
}


/**
 * Problem factory which uses the same arguments as the main from where
 * is called (minimum two arguments)
 * @param argc : Number of arguments
 * @param argv : Array of arguments
 */
Problem * ProblemFactory::getProblem(int argc, char ** argv) {
  if (argc==2) {
    return getProblem(argv[1], 0, NULL);
  } else if (argc>2) {
    char ** argv2 = new char*[argc-2];
    for (int i=0; i<argc-2; i++) {
      argv2[i] = argv[i+2];
    }
    return getProblem(argv[1], argc-2, argv2);
  } else {
    cerr << "Too few arguments to build a problem.";
    exit(-1);
  }
}


/**
 * Problem factory with some optional parameters to be used to construct the
 * problem
 * @param name : Name of the problem
 * @param argc : Number of parameters
 * @param argv : Array of parameters
 */
Problem * ProblemFactory::getProblem(char * name, int argc, char ** argv) {

  if (strcmp(name, "DTLZ1")==0) { // DTLZ1
    if (argc==0)
      return new DTLZ1("Real");
    else if (argc==1)
      return new DTLZ1(argv[0]);
    else if (argc==2)
      return new DTLZ1(argv[0], atoi(argv[1]));
    else if (argc==3)
      return new DTLZ1(argv[0], atoi(argv[1]), atoi(argv[2]));
    else {
      cerr << "Incorrect number of arguments for DTLZ1 problem." << endl;
      exit(-1);
    }

  } else if (strcmp(name, "Fonseca")==0) { // Fonseca
    if (argc==0)
      return new Fonseca("Real");
    else if (argc==1)
      return new Fonseca(argv[0]);
    else {
      cerr << "Incorrect number of arguments for Fonseca problem." << endl;
      exit(-1);
    }

  } else if (strcmp(name, "ZDT1")==0) { // ZDT1
    if (argc==0)
      return new ZDT1("Real");
    else if (argc==1)
      return new ZDT1(argv[0]);
    else if (argc==2)
      return new ZDT1(argv[0], atoi(argv[1]));
    else {
      cerr << "Incorrect number of arguments for ZDT1 problem." << endl;
      exit(-1);
    }

  } else {

    cerr << "ProblemFactory::getProblem: Problem '" << name
        << "' does not exist. Please, check the problem names "
        << "in jmetalcpp/problems" << endl;
    exit(-1);

  }

}

