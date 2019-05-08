---
layout: default
title: Lab 6
permalink: /vision/assignments/2019-1/lab6
---

# Lab 6 - Tensorflow & Neural Networks

Train two models (linear classifier & neural network) to classify images.

You can use the [notebooks](https://github.com/cstopics/cstopics/tree/gh-pages/assets/notebooks/tensorflow){:target="blank"} studied in class as guide.

## Dataset

You must use de CIFAR-10 dataset (introduced [here](http://127.0.0.1:4000/cstopics/vision/10_imageclass){:target="blank"}), this [notebook](https://github.com/cstopics/cstopics/blob/gh-pages/assets/notebooks/vision_notebooks/CNNs/10_NearestNeighbor.ipynb){:target="blank"} shows how to import and use the dataset.

It includes 50000 images for training and 10000 images for testing, and its corresponding labels, you must reshape and reformat them in for your convenience. Consider using the RGB images and converting it to gray images.

*Note: Do not forget that the data_utils.py file is allocated in the same folder that the notebook (i.e. [here](https://github.com/cstopics/cstopics/tree/gh-pages/assets/notebooks/vision_notebooks/CNNs){:target="blank"})*

## 1. Linear Classifier

Review the [linear classifier notes](http://cs231n.github.io/linear-classify/){:target="blank"} and the class notebooks, and train a linear classifier using TensorFlow, to which you enter an image and gives you the corresponding class. Consider starting with [this notebook](https://github.com/cstopics/cstopics/blob/gh-pages/assets/notebooks/tensorflow/ImageRegression.ipynb){:target="blank"}.

## 2. Neural Network

Review the [neural netwoks notes](http://cs231n.github.io/neural-networks-1/){:target="blank"} and train a Neural Network using TensorFlow, to which you enter an image and gives you the corresponding class.

## Measurements

* Accuracy and loss during the training.
* Test Accuracy.

## Report

Write the report in the same notebook.

## Notes

* Consider using *one-hot* encoding for the outputs.
* You can not use Keras.
