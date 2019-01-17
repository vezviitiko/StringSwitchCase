uint64_t constexpr mix(char m, uint64_t s)
 {
  return ((s<<7) + ~(s>>3)) + ~m;
 }
 
uint64_t constexpr hash(const char * m)
 {
  return (*m) ? mix(*m,hash(m+1)) : 0;
 }
  
 void switch_test(const char * str)
 {
  switch( hash(str) ) // run-time
   {
    case hash("tatatututoto"): // compile-time
 
     std::cout << "tutu!" << std::endl;
     break;
 
    case hash("tatatititoto"): // compile-time
      
     std::cout << "titi!" << std::endl;
     break;
      
    default:
      
     std::cout << "wut?" << std::endl;
     break;
   };
 }
 
int main()
 {
 
  switch_test("tatatititoto");
  switch_test("tatatututoto");
  switch_test("abababubabub");
  return 0;
 }

