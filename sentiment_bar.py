import matplotlib.pyplot as plt
import numpy as np

def plot_sentiment_bars():
    '''
    '''
    sentiment_names = ['positive', 'negative', 'neutral']
    sentiment_values = [0.3, 0.1, 0.6]
    offset_dic = {'positive': -0.2, 'negative': 0.2, 'neutral': 0}
    color_dic = {'positive': 'g', 'negative': 'r', 'neutral': 'y'}
    sentiment_dic = {}
    sentiment_dic['positive'] = 0.3
    sentiment_dic['negative'] = 0.6
    sentiment_dic['neutral'] = 0.1
    xvalues = np.array([1,])
    fig, ax = plt.subplots()
    for idx, isent in enumerate(sentiment_names):
    #for isent in ['good', 'bad', 'neutral']:
        ax.bar(xvalues+offset_dic[isent], sentiment_dic[isent],width=0.2,color= color_dic[isent],align='center',edgecolor = "none")
        ax.text(xvalues+offset_dic[isent], sentiment_dic[isent]+0.02, isent, fontsize=30, ha='center', color=color_dic[isent])
        #ax.bar([1,], sentiment_dic[isent], color = color_dic[isent])
    ax.set_ylim([0,1.3*max(sentiment_dic.values())])
    ax.set_yticks([])
    ax.set_xticks([])
    ax.text(xvalues+offset_dic['neutral'], 1.2*max(sentiment_dic.values()),
            'Comment sentiments', fontsize=30, ha='center')
    #plt.title('Comments sentiment', fontsize=30)
    fig.show()
    raw_input('ok...')
if __name__=='__main__':
    plot_sentiment_bars()
