#pragma once
/*



// Hazard pointer record
class  HPRecType {
HPRecType * pNext_;

int active_;
// Global header of the HP list
 	
static HPRecType * pHead_;
// The length of the list
 	
static int listLen_;
 	
public:
// Can be used by the thread
// that acquired it
 	void * pHazard_;
 	
static HPRecType * Head() {
 
return pHead_;
}
// Acquires one hazard pointer
 	
static HPRecType * Acquire() {
// Try to reuse a retired HP record
HPRecType * p = pHead_;
 for(; p; p = p->pNext_) {
 if(p->active_ || !CAS(&p->active_, 0, 1))
	{continue;}
 
  // Got one!
   
  return p;
  }
  // Increment the list length

   int oldLen;
  do {
  oldLen = listLen_;
  }while (!CAS(&listLen_, oldLen, oldLen + 1));
  // Allocate a new one
  HPRecType * p = new HPRecType;
  p->active_ = 1;
  p->pHazard_ = 0;
  // Push it to the front
 do {
  old = pHead_;
  p->pNext_ = old;
  } while (!CAS(&pHead_, old, p));
   
  return p;
  }
  // Releases a hazard pointer
   	   	static void Release(HPRecType* p) {
  p->pHazard_ = 0;
  p->active_ = 0;
  }
  };
  // Per-thread private variable
  __per_thread__ vector<Map<K, V> *> rlist;





    template <class K, class V>
  class  WRRMMap {
  Map<K, V> * pMap_;
  ...
     private:
   	   static void Retire(Map<K, V> * pOld)
	{
  // put it in the retired list
  rlist.push_back(pOld);
   if(rlist.size() >= R)
	{
		 Scan(HPRecType::Head());
	}
	}
 };




   	void Scan(HPRecType * head) {
  // Stage 1: Scan hazard pointers list
  // collecting all non-null ptrs
  vector<void*> hp;
   	 (head) {
   	void* p = head->pHazard_;
   if(p) {hp.push_back(p);}
  head = head->pNext_;
  }
  // Stage 2: sort the hazard pointers
  sort(hp.begin(), hp.end(),less<void*>());
  // Stage 3: Search for’em!
  vector<Map<K, V>*>::iterator i = rlist.begin();
  while	 (i != rlist.end()) {
	if(!binary_search(hp.begin(),  hp.end(), *i) 
	 {
		// Aha!
		delete *i;
  		if (&*i != &rlist.back())
		{
		 *i = rlist.back();
		  }
  rlist.pop_back();
  }   
  else
	{
	 ++i;
	}
  }
 }
  


   	void Update( const  K&k, const V&v)
  {
	Map<K, V> * pNew = 0;
	do {
		Map<K, V> * pOld = pMap_;
		delete pNew;
		pNew = new Map<K, V>(*pOld);
		(*pNew)[k] = v;
		}while (!CAS(&pMap_, pOld, pNew));
  Retire(pOld);
  }



  V Lookup(const K&k)
  {
	HPRecType * pRec = HPRecType::Acquire();
	Map<K, V> * ptr;
	do {
		ptr = pMap_;
		pRec->pHazard_ = ptr;
	}while (pMap_ != ptr);
  // Save Willy
  V result = (*ptr)[k];
  // pRec can be released now
  // because it’s not used anymore
  HPRecType::Release(pRec);
   
  return result;
  }

*/




class HazardPointer
{
public:
	HazardPointer();
	~HazardPointer();
};

