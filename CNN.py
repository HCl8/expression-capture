import cv2
import numpy as np
from keras.layers import Activation, Conv2D
from keras.layers import BatchNormalization
from keras.layers import GlobalAveragePooling2D
from keras.models import Model
from keras.layers import Input
from keras.layers import MaxPooling2D
from keras.layers import SeparableConv2D
from keras import layers
from keras.regularizers import l2


def LoadModel():
    # 0=Angry, 1=Disgust, 2=Fear, 3=Happy, 4=Sad, 5=Surprise, 6=Neutral
    model = mini_XCEPTION((48, 48, 1), 7)
    # model = keras.models.load_model("F:\\HCl\\database\\Emotion Recognition\\models\\_mini_XCEPTION.01-0.70.hdf5")
    model.load_weights("data.bin")
    return model

def Show(image):
    cv2.imshow(" ", image)
    cv2.waitKey()


def preprocess_input(x, v2=True):
    x = x.astype('float32')
    x = x / 255.0
    if v2:
        x = x - 0.5
        x = x * 2.0
    return x


def model_predict(models, image):
    image = np.reshape(image,(1, 48, 48, 1))
    image = preprocess_input(image)
    return models.predict(image).tolist()


def mini_XCEPTION(input_shape, num_classes, l2_regularization=0.01):
    regularization = l2(l2_regularization)

    # base

    img_input = Input(input_shape)

    x = Conv2D(8, (3, 3), strides=(1, 1), kernel_regularizer=regularization,

               use_bias=False)(img_input)

    x = BatchNormalization()(x)

    x = Activation('relu')(x)

    x = Conv2D(8, (3, 3), strides=(1, 1), kernel_regularizer=regularization,

               use_bias=False)(x)

    x = BatchNormalization()(x)

    x = Activation('relu')(x)

    # module 1

    residual = Conv2D(16, (1, 1), strides=(2, 2),

                      padding='same', use_bias=False)(x)

    residual = BatchNormalization()(residual)

    x = SeparableConv2D(16, (3, 3), padding='same',

                        kernel_regularizer=regularization,

                        use_bias=False)(x)

    x = BatchNormalization()(x)

    x = Activation('relu')(x)

    x = SeparableConv2D(16, (3, 3), padding='same',

                        kernel_regularizer=regularization,

                        use_bias=False)(x)

    x = BatchNormalization()(x)

    x = MaxPooling2D((3, 3), strides=(2, 2), padding='same')(x)

    x = layers.add([x, residual])

    # module 2

    residual = Conv2D(32, (1, 1), strides=(2, 2),

                      padding='same', use_bias=False)(x)

    residual = BatchNormalization()(residual)

    x = SeparableConv2D(32, (3, 3), padding='same',

                        kernel_regularizer=regularization,

                        use_bias=False)(x)

    x = BatchNormalization()(x)

    x = Activation('relu')(x)

    x = SeparableConv2D(32, (3, 3), padding='same',

                        kernel_regularizer=regularization,

                        use_bias=False)(x)

    x = BatchNormalization()(x)

    x = MaxPooling2D((3, 3), strides=(2, 2), padding='same')(x)

    x = layers.add([x, residual])

    # module 3

    residual = Conv2D(64, (1, 1), strides=(2, 2),

                      padding='same', use_bias=False)(x)

    residual = BatchNormalization()(residual)

    x = SeparableConv2D(64, (3, 3), padding='same',

                        kernel_regularizer=regularization,

                        use_bias=False)(x)

    x = BatchNormalization()(x)

    x = Activation('relu')(x)

    x = SeparableConv2D(64, (3, 3), padding='same',

                        kernel_regularizer=regularization,

                        use_bias=False)(x)

    x = BatchNormalization()(x)

    x = MaxPooling2D((3, 3), strides=(2, 2), padding='same')(x)

    x = layers.add([x, residual])

    # module 4

    residual = Conv2D(128, (1, 1), strides=(2, 2),

                      padding='same', use_bias=False)(x)

    residual = BatchNormalization()(residual)

    x = SeparableConv2D(128, (3, 3), padding='same',

                        kernel_regularizer=regularization,

                        use_bias=False)(x)

    x = BatchNormalization()(x)

    x = Activation('relu')(x)

    x = SeparableConv2D(128, (3, 3), padding='same',

                        kernel_regularizer=regularization,

                        use_bias=False)(x)

    x = BatchNormalization()(x)

    x = MaxPooling2D((3, 3), strides=(2, 2), padding='same')(x)

    x = layers.add([x, residual])

    x = Conv2D(num_classes, (3, 3),

               # kernel_regularizer=regularization,

               padding='same')(x)

    x = GlobalAveragePooling2D()(x)

    output = Activation('softmax', name='predictions')(x)

    model = Model(img_input, output)

    return model