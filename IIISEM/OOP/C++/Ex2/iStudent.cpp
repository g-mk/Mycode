#include"hStudent.h"
float CalculateCutoff ( struct SStudent Candidate, int nCategory, int nBonus)
{
 float fCutoff;
 switch(nCategory)
  {
    case 1: fCutoff = Candidate.m_fMarks[0] * 0.5 + ((Candidate.m_fMarks[1]+
                     Candidate.m_fMarks[2]) /2) * 0.25 +Candidate.m_fMarks[3] * 0.25;
                     break;
    case 2: fCutoff = Candidate.m_fMarks[0] * 0.45 + ((Candidate.m_fMarks[1]
                     + Candidate.m_fMarks[2])/2) * 0.2 +Candidate.m_fMarks[3] * 0.35;
                     break;
    case 3: fCutoff = Candidate.m_fMarks[0] * 0.4 + ((Candidate.m_fMarks[1]
                     + Candidate.m_fMarks[2])/2) * 0.2 +Candidate.m_fMarks[3] * 0.4;
                     break;
   default: cout << "No Such Category...\n";
            return -1;
  }
 
 fCutoff += nBonus;
 if(fCutoff > 200 )
     return 200;
 else 
     return fCutoff;
}

