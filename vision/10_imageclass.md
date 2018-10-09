---
layout: default
title: Image Classification
permalink: /vision/10_imageclass
---

Table of contents:

- [Introduction](#intro)
    - [Challenges](#challenges)
    - [Dataset](#dataset)
    - [Learning Processes](#learning)
    - [Accuracy](#accuracy)
- [Nearest Neighbor Classifier](#nearest)
- [k - Nearest Neighbor Classifier](#knearest)
- [Validation Set](#validation)
    - [Cross-Validation](#crossvalidation)
- [Advantages and Drawbacks of the Nearest Neighbor Classifier](#proscons)

<a name='intro'></a>
<h1 style="text-align: center;">Image Classification</h1>

The idea of classify images is to select a label that represents in the best way (in human terms) its content, giving the machines a taste of human interpretation or perception of the world, in a high abstraction level.

For people is easy to identify the present object in an image (through complex and not completely understood processes inside our brain), nevertheless, the machine sees only a set of numbers, arranged as a data matrix of dimension <img src=" https://latex.codecogs.com/gif.latex? W \times H \times C "/> (<img src=" https://latex.codecogs.com/gif.latex? C=1 "/> in gray-level images and <img src=" https://latex.codecogs.com/gif.latex? C=3 "/> in RGB images).

Consider the following image, where a car is in it. It has <img src=" https://latex.codecogs.com/gif.latex? 693 \times 511 "/> pixels, so <img src=" https://latex.codecogs.com/gif.latex? 693 \times 511 \times 3 = 1,062,369"/> numbers from 0 to 255.The task of our classification algorithm it to convert that million of values in only one label, such as "car".

<div class="picture">
    <img style="width:90%;" src ="/cstopics/assets/img/vision/10_carclass.png" />
</div>

<a name='challenges'></a>
## Challenges

Considering that images are RAW 3D representations, there are some challenges that the classifiers must face:

* ***Scale Variation:*** A same class of object can be present (both in the image capture and in the reality) in different sizes.

<div class="picture">
    <img style="width:40%;" src ="/cstopics/assets/img/vision/10_ch1_dogs.png" />
</div>

* ***Intra-class variation*** Same class could include very different subtypes, for example, shoes:

<div class="picture">
    <img style="width:40%;" src ="/cstopics/assets/img/vision/10_ch2_shoes.png" />
</div>

* ***Illumination conditions*** Conditions induced by different angles and intensities in the illumination.

<div class="picture">
    <img style="width:60%;" src ="/cstopics/assets/img/vision/10_ch3_light.png" />
</div>

* ***Occlusion:*** Occasionally, some of the pixels (or even the majority of them) corresponding to the object, are no visible from the view point of the camera.

<div class="picture">
    <img style="width:40%;" src ="/cstopics/assets/img/vision/10_ch4_oclution.png" />
</div>

* ***Viewpoint variation:*** The capture could be taken from different points.

<div class="picture">
    <img style="width:40%;" src ="/cstopics/assets/img/vision/10_ch5_boat.png" />
</div>

* ***Deformation:*** Objects are not always in its original shape.

<div class="picture">
    <img style="width:40%;" src ="/cstopics/assets/img/vision/10_ch6_deformation.png" />
</div>

* ***Background clutter:*** Object can be 'camouflaged' in the background.

<div class="picture">
    <img style="width:40%;" src ="/cstopics/assets/img/vision/10_ch7_back.png" />
</div>

<a name='dataset'></a>
## Dataset

As you are going to learn, you will need sets of image samples, to 'teach' your algorithm how each class looks. In the case of supervised learning (the one we are going to study), the datasets must be labeled, that means that for each image, you must know its label:

<div class="picture">
    <img style="width:60%;" src ="/cstopics/assets/img/vision/10_dataset.png" />
    <div>https://blog.webkid.io/datasets-for-machine-learning/</div>
</div>

<a name='learning'></a>
## Learning process

The process of creating a supervised learning model can be expressed as follows:

<div class="picture">
    <img style="width:90%;" src ="/cstopics/assets/img/vision/10_learning_process.png" />
    <div>https://blog.webkid.io/datasets-for-machine-learning/</div>
</div>

* ***Input Images:*** The dataset is sorted, formated, and prepared for the learning algorithm.

* ***Set Hyperparameters:*** Hyperparameters are the parameters that user establish for the model structure, learning process, etc.

* ***Training:*** The learning algorithm is executed.

* ***Change hyperparameters:*** Sometimes it is necessary to perform a hyperparameters sweep, in order to find he best combination of them, that implies the best performance.

* ***Store Model to for Production Using:*** Store the learned parameters of your model, to be used in the final application.

<a name='accuracy'></a>
## Accuracy

It is usually a number from 0.0 to 1.0 (0% to 100%), and indicates the percentage of samples of the test dataset that were correctly classified.

<a name='nearest'></a>
# Nearest Neighbor Classifier

This algorithm is only a learning exercise, and is very rarely used in practice. Its idea is to generate a idea of the image classification problem.

For this case, the learning process is omitted, when an image is to be classified, it is measured the distance between it and all the images of the dataset, and the label of the closest one would be the label of the tested image.Nearest Neighbor Classifier

* ***L1 Distance:*** The simples way to compare two images is with the **L1 distance**, where the difference, pixel to pixel, is computed, and the total sum is the distance between the images:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  d_{L1} (I_1, I_2) = \sum_{i=0}^{W-1} \sum_{j=0}^{H-1} \sum_{c=0}^{channels-1} | I_1(i,j,c) - I_2(i,j,c) |
"/>

<img src=" https://latex.codecogs.com/gif.latex? 5 \times 5 "/>, gray image example:

<div class="picture">
    <img style="width:90%;" src ="/cstopics/assets/img/vision/10_distance_L1.png" />
</div>

* ***L1 Distance:*** Another common way to measure distance is the **L2 distance**, that is the euclidean distance:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  d_{L1} (I_1, I_2) = \sqrt{ \sum_{i=0}^{W-1} \sum_{j=0}^{H-1} \sum_{c=0}^{channels-1} (I_1(i,j,c)-I_2(i,j,c)^2 }
"/>

The squared root is added above because of the mathematical definition of the euclidean distance, but it is a *monotonic function*, that means that it preserves the order, so if you remove it, you are going to get the same result.

Check the implementation in the [notebook](https://github.com/cstopics/cstopics/blob/gh-pages/assets/notebooks/vision_notebooks/CNNs/10_NearestNeighbor.ipynb){:target="blank"}

<a name='knearest'></a>
# k - Nearest Neighbor Classifier

The idea of choosing the nearest element can produce wrong labeling. The kNN classifier find the ***k*** nearest closest images, and from their labels, it is chosen the more repeated. So the *Nearest Neighbor Classifier* is a specific case with <img src=" https://latex.codecogs.com/gif.latex? k=1 "/>. Usually, bigger values of *k* produce more resistance to outliers in the classifier.

The following example show the "boundaries" of the classification for <img src=" https://latex.codecogs.com/gif.latex? k=1 "/> (second plot) and <img src=" https://latex.codecogs.com/gif.latex? k=5 "/> (third plot). You can see that the second one has litle *islands* of green inside the red region. The third one removes that *islands* and makes the boundaries softter.

<div class="picture">
    <img style="width:32%;" src ="/cstopics/assets/img/vision/10_knn_1.png" />
    <img style="width:32%;" src ="/cstopics/assets/img/vision/10_knn_2.png" />
    <img style="width:32%;" src ="/cstopics/assets/img/vision/10_knn_3.png" />
    <div>https://en.wikipedia.org/wiki/K-nearest_neighbors_algorithm</div>
</div>

<a name='validation'></a>
# Validation Set

If you want to use a kNN classifier, what number for *k* should you choose?, and which distance, between *L1* and *L2*, should you use?. These variables are called *hyperparameters*, and are the properties or parameters of you classification algorithm that are not learned in the training process.

The first idea you could think is to train with each combination of *hyperparameters*, and choose the best, according to the performance, or accuracy, obtained with the *test dataset*. But be carefull, **you can not use the test dataset to choose the *hyperparameters**. The test dataset is a resource that you must only use for the final test, if not, you could be *overfitting* your model, becouse you are using you *test dataset* as a *train dataset*. Additionally, you would not have data to measure the *generalization* of your model.

> Use the test dataset only one single time, at the end.

The way to face this situation is to extract a small portion of the *training set*, and use it as a *validation set*. For example, if you have a *training set* with 50,000 samples, you can extract 1,000 for your *validation set*, and the rest for your new *training set* (49,000).

<a name='crossvalidation'></a>
## Cross-Validation

If you have a small *trining set*, you can use a technique called *cross-validation* (with large dataset could become very computationally expensive). In this case, you split your training set in, for example, 5 parts or folds (6 including the test set). Then you train your model with 4 of the 5 folds, and validate it with the another one. Repeat this procedure 5 times, changing the validation fold, and average the 5 accuracy values. That is the accuracy with the selected combination of hyperparameters.

<div class="picture">
    <img style="width:100%;" src ="/cstopics/assets/img/vision/10_crossvalidation.png" />
</div>

<a name='proscons'></a>
## Advantages and Drawbacks of the Nearest Neighbor Classifier

Pros:
- Simple to implement and understand.
- No time to train.

Cons:
- So much time in predicting.

Another problem is that L1 and L2 distances are not completely related to the content of the image, for example, the following images have he same objects, but some modification induce high mathematical distances.

<div class="picture">
    <img style="width:100%;" src ="/cstopics/assets/img/vision/10_cat.png" />
</div>

The pixel difference is usually related to background color, and brightness similarity. When you use a visualization technique called t-SNE (locate samples near to small distance pairs) to plot the similarity of the CIFAR-10 images, you get this [image](/cstopics/assets/img/vision/10_t-SNE.jpg).

There, you can see that similar background and brightness images are close.
