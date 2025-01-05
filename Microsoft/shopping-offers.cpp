class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) 
    {
        unordered_map<int, int> cache;
        return shoppingOffersImp(price, special, needs, cache);
    }

    int shoppingOffersImp( vector<int>& price, vector<vector<int>>& special, vector<int>& needs, unordered_map<int, int>& cache)
    {
        int state = needsToState(needs);
        if (cache.find(state) != cache.end())return cache[state];

        int minPrice = 0;
        for (int i = 0; i < needs.size(); ++i) minPrice += needs[i] * price[i];

        for (int i = 0; i < special.size(); ++i)
        {
            if (isOfferUsable(special[i], needs))
            {
                vector<int> newNeeds = needs;
                reduceByOffer(special[i], newNeeds);

                int offerPrice = special[i].back();
                int pricei = offerPrice + shoppingOffersImp(price, special, newNeeds,cache);

                minPrice = min(minPrice, pricei);
            }
        }

        cache[state] = minPrice;
        return minPrice;
    }

    void reduceByOffer(vector<int>& specialOffer, vector<int>& needs)
    {
        for (int i = 0; i < needs.size(); ++i)
            needs[i] -= specialOffer[i];
    }

    bool isOfferUsable(vector<int>& specialOffer, vector<int>& needs)
    {
        for (int i = 0; i < needs.size(); ++i)
            if (needs[i] < specialOffer[i])
                return false;

        return true;
    }

    int needsToState(vector<int>& needs)
    {
        int r = 0;
        int d = 1;

        for (int i = 0; i < needs.size(); ++i)
        {
            r += d*needs[i];
            d = d * 10;
        }

        return r;
    }
};