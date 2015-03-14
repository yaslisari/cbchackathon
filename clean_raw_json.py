import collections
import json


def clean_raw_file(fname, outname = 'raw_comments/test_cleaned.json'):
    '''
    Cleans the json-format file to have only comments
    '''
    
    ##Load the raw comments
    db = json.load(open(fname))

    ##Filling comments in a dictionary
    ##This dic will contain the comments with format {comment#: comment string}
    comment_dic = collections.OrderedDict()
    for idx, idb in enumerate(db['collection1']):
        comment_dic[idx] = idb['property1']

    ## Put in a json format also human readable
    j = json.dumps(comment_dic, indent=4)
    f = open(outname, 'w')
    print >> f, j
    f.close()
    print 'Cleaned comment saved in {}'.format(outname)

if __name__=='__main__':
    clean_raw_file('raw_comments/kimonoData_bill-c-51-opponents-plan-day-of-action-to-protest-new-policing-powers.json')
    
