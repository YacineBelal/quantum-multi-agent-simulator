#include <iostream>
#include <unistd.h>

#include "MAS.h"

#include "QuBit.h"
#include "Prog.h"

using namespace std;

int main(void)
{

 Scheduler sched;
 sched.setRandomMode(true);       // Passage en ordonnancement aleatoire
 sched.setRealTimeMode(false);    // Passage en mode NON "temps reel"


 //-- Creation de 3 QuBits

 QuBit* q;

 try { 
      q = new QuBit(1,0);
      cout << "Creation de " << q->getName() << endl;
     }
 catch(string e) { cout << e << endl; }

 try { 
      q = new QuBit(0,1);
      cout << "Creation de " << q->getName() << endl;
     }
 catch(string e) { cout << e << endl; }


  try { 
      q = new QuBit(0,1);
      cout << "Creation de " << q->getName() << endl;
     }  
 catch(string e) { cout << e << endl; }


 //-- Creation du Programme

 Prog* prog = new Prog(true); // decoherence mode set at true
 cout << "Creation de " << prog->getName() << endl;
 cout << *prog << endl;
#if 1
 prog->suspend();
#endif


 sleep(2);

 cout << endl;

 vector<Agent*> v; getAllAgents("QuBit",v);

 while (1)
 {
  cout << "***>" << endl;
  if (prog->isFinished())  break;
  if (prog->isSuspended()) prog->live(0);

  cout << "====> Start cycle" << endl;

  sched.cycle();   // methode void live(double dt) de chacun des Agents

  cout << "<==== End cycle" << endl;

  cout << "---------------- Treatment of all messages after cycle ---" << endl;
  size_t nbMessages;
  do
  {
   nbMessages = 0;
   for(size_t i=0;i<v.size();i++)
   {
    QuBit* agent=(QuBit*)v[i];
    if (exist(agent))
      nbMessages += agent->treatAllMessages();
   }
  } while(nbMessages!=0);

  cout << "---------------- QuBit synchronization after cycle -------" << endl;
  for(size_t i=0;i<v.size();i++)
  {
   QuBit* agent=(QuBit*)v[i];
   if (exist(agent))
     agent->synchronizeQuBit();
  }
  
  cout << "<***" << endl;
  cout << endl;
 }

 cout << "Final QuBit States:" << endl;

 for(size_t i=0;i<v.size();i++)
 {
  cout << *v[i] << endl;
 }

 return 0;   // A la fin, lorsque l'ordonnanceur est detruit, tous les agents
}            // connus par l'ordonnanceur sont automatiquement detruits.
