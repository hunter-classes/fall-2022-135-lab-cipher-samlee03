#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

// add your tests here

TEST_CASE("Decryption with Distance Formula Test"){
  CHECK(solve("this is a sentence that is already decrypted. it contains all of the characters in the english language. some characters in the english language appears more often than others.") == "this is a sentence that is already decrypted. it contains all of the characters in the english language. some characters in the english language appears more often than others.");
  CHECK(solve("pu aol lunspzo hswohila, aolyl hyl adluaf zpe johyhjalyz. ovdlcly, aolyl hyl jlyahpu johyhjalyz aoha hwwlhy tvyl aohu vaolyz. mvy puzahujl, aol vjjbylujlz vm cvdlsz pz nylhaly aohu thuf jvuzvuhua.") == "in the english alphabet, there are twenty six characters. however, there are certain characters that appear more than others. for instance, the occurences of vowels is greater than many consonant.");
  CHECK(solve("wixcha cm u lyfuncpyfs nywbhcwuf zcyfx iz mnoxs nbun nsjcwuffs lykoclym u gchcgog iz u ziol-syul xyalyy ni yzzywncpyfs qile um u jlialuggyl, nbioab nbcm cmh'n guhxunils. migy wixylm uly myfz-nuoabn il mnuln qcnb u gily gixymn nqi-syul jlialug uhx nbyh fyulh ih nby div. von un cnm wily, wigjonyl jlialuggcha cm u zuclfs mnlucabnzilqulx nume.") == "coding is a relatively technical field of study that typically requires a minimum of a four-year degree to effectively work as a programmer, though this isn't mandatory. some coders are self-taught or start with a more modest two-year program and then learn on the job. but at its core, computer programming is a fairly straightforward task.");
  CHECK(solve("s kw wkusxq ez k bkxnyw coxdoxmo. drsc coxdoxmo sc xyd zkbdsmevkbvi fobi sxdobocdsxq, led drobo kbo k vyd yp voddobc drkd knn ez dy dro pboaeoxmi yp okmr voddob.") == "i am making up a random sentence. this sentence is not particularly very interesting, but there are a lot of letters that add up to the frequency of each letter.");
}
