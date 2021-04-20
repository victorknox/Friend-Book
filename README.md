# Friends-recommendation-system
A simple friends recommendation system resembling that of facebook's 

# Question statement

## A.    Legend

You  are  fascinated  about  how  Facebook  manages  to recommend friends which are in most of the cases related to us in some ways.  So you decided to come up with your own system to recommend friends.  Of-course, it won’t besome complex ML stuff!!

## B. Specifications

### 1. User

1. Users can register in your system. Each user will have some parameters like name,age,city,etc. Also there must be some unique ID for every user. The ID should be a minimum positive integer which is not currently in use.
2. Users can unregister from your system. After a user unregisters from the system, its ID can be used by another user.
3. Each user has a collection of users which are call edits friends.  Note that it is possible that user ‘A’ isa friend of user ‘B’ but not vice versa.  If a friend unregisters from the system, then that friend mustbe removed from his friends list.

### 2. Friends Recommendation
1. For already registered users, show top ‘K’ rec-ommendations.   Recommendation  should  be  doneas follows:  
2. A friend should not be recommended.  
3. All  second  friends  (friends  of  friends)  should  begiven  more  preference  than  all  third  friends.   Allthird friends should be given more preference thanall fourth friends and so on.  
4. For two friends which are bothithfriend, they willbe preferred in random order.
5. When  a  new  user  is  registering  in  the  sys-tem, show top 10 recommendations based on somecommon parameters.  The more parameters a userhas  in  common,  the  more  preferred  it  will  be. If two  users  have  the  same  number  of  common  pa-rameters, then choose randomly.  
6. If  the  number  of  already  registered  users  are  lessthan or equal to 10, then show all the users.  
7. If the number of already registered users are greaterthan but the number of users with some common parameters  are  less  than  10,  then  show  all  thoseusers  with  common  parameters  and  then  showother users randomly such that they are all 10 intotal.  
8. Let, the number of recommended users be K, nowthe  new  registering  user  would  add  any  X  (≤k)users  to  friends.   ‘K’  along  with  the  list  of  ID  offriends would be given as an input.

### 3. Check Friendship Status
1. You will be given an ID of two users A and B and you have to tell whether A is a friend of B or not.
2. You have to do this operation efficiently, the more efficient  this  operation  will  be,  the  more  marks would be given for this part.

## C.    Evaluation and other comments
1. You  will  be  evaluated  on  how  well  you  have  im-plemented the features and with what complexity(both space and time would be considered).
2. You can come up with your own user interface.  Foruser  Interface  we  are  not  expecting  anything  be-yond command line, but you are welcome to createother exciting interfaces.

