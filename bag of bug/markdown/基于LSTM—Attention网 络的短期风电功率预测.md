基于LSTM—Attention网 络的短期风电功率预测





人类大脑在观察某一事物时, 往往会将注意力 集中到事物的某些部分, 这些注意力集中的部分往 往也是从事物上获取信息的关键, 这些信息对于认 知同类事物有着很强的指引作用, 而注意力机制 (attention mechanism)[25] 就是一种模仿这一认知 过程的特殊机制. 注意力机制在计算机视觉和自然 语言处理领域的运用已经取得了较好的结果[26,27]





[25] Mnih V, Heess N, Graves A, Kavukcuoglu K 2014 Proceedings of the 27th International Conference on Neural Information Processing Systems Montreal, Canada, December 8-13 2014, p2204



[26] Yin W, Schütze H, Xiang B, Zhou B 2015 arXiv: 1512.05193 [cs.CL]



[27]Vaswani A, Shazeer N, Parmar N, Uszkoreit J, Jones L, Gomez A N, Kaiser L, Polosukhin I 2017 Proceedings of the 31st International Conference on Neural Information Processing Systems Long Beach, USA, December 4-9 2017, p6000



注意力模型能够通过提取关键特征解决某些问题, 使得预测精度有所提升.

基于内容的注意力机制使神经图灵机可以在他们的存储器中进行搜索并重点关注于他们所寻找的目标相匹配的位置，而基于位置的注意力机制则使存储单元中注意力的相对运动成为了可能，使神经图灵机能够循环。

注意力机制是在计算能力有限的情况下，将计算资源分配给更重要的任务，同时解决信息超载问题的一种资源分配方案



传统的内存和基于模型的方法中运用深度学习计数来构建模型，解决群组推荐，可以动态地进行用户权重的调研。对于用户分配不同的权重进行不同群组的行为分析，取决于用户相关的专业知识。当前的前沿方法时针对聚合群组织成员的偏好，再提供策略，忽略群组中用户之间的交互转而考虑群组项目和用户项目的交互，讨论用户的偏好和意见。   而注意力群体推荐模型，采用的时新颖的深度学习方法，将注意力机制计数应用子啊群组推荐中，采用神经网络群组推荐算法，对数据集进行广泛的实验建筑模型，开发基于AGRR的推荐方法，获取参数效率高，模型构建速度快。

注意力机制和Faster RCNN相结合较于传统Faster RCNN算法具有较好的定位和识别准确度，能够为输电线路绝缘子缺陷监测的进一步研究提供准确可靠的信息。

传统的绝缘子识别方法有利用目标颜色特征进行阈值分割的识别法[3] 、基于轮廓特征的定位方法[4] 等。然而，这些方法需要人工设计目标特 征，并且针对不同的目标场景需要设计不同的特 征，无法避免人为主观因素导致的漏检或误检， 识别准确率低。与传统方法相比，卷积神经网络 (convolutional neural network，CNN) 能够从图像中 自动提取表达能力更强的特征 ，减少识别时间， 提高分类和识别的准确率。后来又使用CNN方法实现绝缘子的自动定位,又或者是在R-FCN模型的基础上引入ASDN层,以此来提高绝缘子识别的准确率.文献 [5] 中利用 Faster RCNN 框架对绝缘子进行识别，取得了较好的识别效果。但在 Faster RCNN 识别过程中，由 RPN 得到的目标建议框定位不够精确，影响后续精确 定位结果，导致识别准确率不够理想。 针对以上问题，本文提出注意力机制与 Faster RCNN 相结合的绝缘子识别算法。首先在 Faster RCNN 网络的特征提取阶段引入 Hu 等 [6] 提出的 基于注意力机制的 SENet 结构，使网络能够自动 学习到每个特征通道的重要程度，关注与目标相 关的特征通道而抑制与目标不相关的特征通道， 提升网络性能；然后，在 RPN 生成 anchor 阶段，根 据绝缘子特点，改进基础 anchor 比例和尺度；最 后，结合注意力机制计算建议框之间相互依赖关 系的权重，融合周围建议框的特征向量来更新每 一个目标建议框的特征向量，使目标建议框的特 征向量包含更准确的位置信息，促进识别准确率 的提升，进一步提高绝缘子识别精度。

Traditional insulator recognition methods include the use of target color features for threshold segmentation [3] and contour feature-based positioning methods [4]. However, these methods require manual design of target features, and different features need to be designed for different target scenarios. Missing or misdetection caused by human subjective factors cannot be avoided, and the recognition accuracy is low. Compared with traditional methods, convolutional neural network (CNN) can automatically extract more expressive features from images, reduce recognition time, and improve classification and recognition accuracy. Later, the CNN method was used to realize the automatic positioning of insulators, or the ASDN layer was introduced on the basis of the R-FCN model to improve the accuracy of insulator identification. In [5], the Faster RCNN framework was used to identify insulators. A good recognition effect has been achieved. However, in the recognition process of Faster RCNN, the target suggestion frame location obtained by RPN is not accurate enough, which affects the follow-up precise positioning result, resulting in unsatisfactory recognition accuracy. In response to the above problems, this paper proposes an insulator identification algorithm combining the attention mechanism and Faster RCNN. First, in the feature extraction stage of the Faster RCNN network, the SENet structure based on the attention mechanism proposed by Hu et al. [6] is introduced, so that the network can automatically learn the importance of each feature channel, focusing on the feature channel related to the target and suppressing the target Irrelevant feature channels to improve network performance; then, in the anchor generation stage of the RPN, improve the basic anchor ratio and scale according to the characteristics of the insulator; finally, combine the attention mechanism to calculate the weight of the interdependence between the suggestion boxes, and merge the surrounding suggestion boxes The feature vector of each target suggestion box is updated to make the feature vector of the target suggestion box contain more accurate position information, which promotes the improvement of recognition accuracy and further improves the accuracy of insulator recognition.



[3]HUANG Xiaoning, ZHANG Zhenliang. A method to extract insulator image from aerial image of helicopter patrol[J]. Power system technology, 2010, 34(1): 194–197

[4]IRUANSI U, TAPAMO J R, DAVIDSON I E. An active contour approach to insulator segmentation[C]//AFRICON 2015. Addis Ababa, Ethiopia, 2015: 1–5.

[5]CHENG Haiyan, ZHAI Yongjie, CHEN Rui. Faster RCNN based recognition of insulators in aerial images[J]. Modern electronics technique, 2019, 42(2): 98–102.



[6]HU Jie, SHEN Li, SUN Gang. Squeeze-and-excitation networks[C]//Proceedings of 2018 IEEE/CVF Conference on Computer Vision and Pattern Recognition. Salt Lake City, USA, 2018: 7132–7141.



本文将介绍注意力机制的原理以及注意力机制的分类,接着写出了注意力机制在电力系统中的一些应用以及在我国的电力系统中的应用,还介绍了注意力机制在神经网络系统中的作用以及帮助神经网络效率的提升,最后对注意力机制在电力系统中的应用作了一些展望以及我国电力系统中还能运用哪些注意力机制.



注意力机制的分类

① Hard/Soft Attention

我们常用的attention 为Softattention,每个权重取值范围为[0,1]对于Hard Attention来说，每个key的注意力只会取0或者1，也就是说我们只会令某几个特定的key有注意力，且权重均为1。

②Global/Local Attention

 一般不特殊说明的话，我们采用的Attention都是GlobalAttention。根据原始的Attention机制，每个解码时刻，并不限制解码状态的个数，而是可以动态适配编码器长度，从而匹配所有的编码器状态.在长文本中我们对整个编码器长度进行对齐匹配，可以会导致注意力不集中的问题，因此我们通过限制注意力机制的范围，令注意力机制更加有效。在LocalAttention中，每个解码器的ht对应一个编码器位置pt，选定区间大小D（一般是根据经验来选的），进而在编码器的[pt-D,pt+D]位置使用Attention机制,根据选择的pt不同，又可以把Local Attention分为Local-m和Local-p两种。

③ Hierarchical Attention

Hierarchical Attention也可以用来解决长文本注意力不集中的问题，与Local Attention不同的是，Local Attention强行限制了注意力机制的范围，忽略剩余位置；而Hierarchical Attention使用分层思想，在所有的状态上都利用了注意力机制

这篇文章介绍了注意力机制和编解码模型，并分析了它们在现实生活中的应用。并且介绍了注意力机制在电力系统中的一些应用.目前来说,注意力机制在电力系统中的应用并不成熟,对注意力机制的应用还是在初步阶段. 注意力机制种类较多,我们目前运用的基本是软注意力,我们可以去尝试使用其他种类的注意力机制,将其引入对电力系统的监管中,让注意力机制去代替传统的识别方法,如基于目标颜色或者轮廓识别方法,提高监管效率以及准确率等.注意力不仅可以用在图像处理方面,还可用在文本处理以及情绪分析等方面,我们可以利用这点来分析电力系统中的员工状态,以防出现危险.文中还给出了注意力机制给传统神经网络带来了提升,因为其允许我们直接检查深度学习体系结构的内部工作,因此注意力是解释神经模型的内部工作的重要途径之一.近年来,源于生物的注意力机制在以不同的方式被各行各业所利用,为研究开辟了许多新的途径,相信以后在电力系统方面注意力机制也能有更出色的表现.

