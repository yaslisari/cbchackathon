import collections
import json
import os

def clean_raw_file(fname, outname = 'raw_comments/test_cleaned.json'):
    '''
    Cleans the json-format file to have only comments
    '''
    ##Title of the article is assumed to be the file basename
    story_title = os.path.basename(fname)
    story_title = os.path.splitext(story_title)[0]
    story_title = story_title.replace('kimonoData_', '')
    print story_title
    
    
    ##Load the raw comments
    db = json.load(open(fname))

    ##Filling comments in a dictionary
    ##This dic will contain the comments with format {comment#: comment string}
    comment_dic = collections.OrderedDict()
    comment_dic['article'] = collections.OrderedDict()
    comment_dic['article']['title'] = story_title
    comment_dic['article']['comments'] = []
    print db['collection1'][0]
    for idx, idb in enumerate(db['collection1']):
        #comment_dic['article']['title']['comments'] = idb['property1']
        comment_dic['article']['comments'].append({'comment': idb['property1']})

    ## Put in a json format also human readable
    j = json.dumps(comment_dic, indent=4)
    f = open(outname, 'w')
    print >> f, j
    f.close()
    print 'Cleaned comment saved in {}'.format(outname)

if __name__=='__main__':
    clean_raw_file('raw_comments/kimonoData_bill-c-51-opponents-plan-day-of-action-to-protest-new-policing-powers.json')
    
