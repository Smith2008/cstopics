---
layout: default
title: Lab 3
permalink: /vision/assignments/lab3
---

# Lab 3

Write a python program that evaluate the answers of a multiple choice exam. There will be ten questions, and student could choose A, B, C or D. The program must receive as arguments the path of the image, and the path of text file containing the correct answers.

The program must apply the necessary image processing procedures, and print the score (between 0.0 and 5.0). In this way:

``` bash
$ checkExam.py -a ./answers.txt -i ./image.jpg
Checking the exam:
1. Answer: A, Correct: A, OK
2. Answer: B, Correct: C, FAIL
3. Answer: B, Correct: B, OK
4. Answer: D, Correct: D, OK
5. Answer: NOT_VALID, Correct: B, FAIL
6. Answer: D, Correct: D, OK
7. Answer: B, Correct: C, FAIL
8. Answer: A, Correct: B, FAIL
9. Answer: EMPTY, Correct: B, FAIL
10. Answer: D, Correct: D, OK
Score: 5/10 = 2.5
$
```

The EMPTY condition happens when the student did not choose any option, and the NOT_VALID condition when the student chose more that one option.

The answers file has the following format:

```
1A
2B
3C
4A
5C
6A
7B
8D
9C
10A
```

The image can be taken from different angles and distances, but the area of the paper could be minimum 1/4 of the image. Check the following examples:

<div class="picture">
  <img style="width:50%;" src ="/cstopics/assets/img/vision/lab3_1.jpg" />
  <img style="width:50%;" src ="/cstopics/assets/img/vision/lab3_2.jpg" />
  <img style="width:50%;" src ="/cstopics/assets/img/vision/lab3_3.jpg" />
  <img style="width:50%;" src ="/cstopics/assets/img/vision/lab3_4.jpg" />
  <img style="width:50%;" src ="/cstopics/assets/img/vision/lab3_5.jpg" />
</div>



Create a new **private** Bitbucket repository named *"2018_2_av_lab3_Lastname1Firstname1_Lastname2Firstname2"* (E.g. *"2018_2_av_lab3_CamachoCamilo_SuarezYeison"*),  share it with the account *"camilocamachousta"*. Inside it  add all your lab files.

When the homework is ready, download the repository as a *.zip* file and upload it to the appropriate link in moodle.

Deadline: Oct 2
