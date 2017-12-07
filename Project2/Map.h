//
//  Project 2
//
//  Created by Daniela Isabel Travieso on 12/1/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//
/*
 Makin' music is what we do
 Tryin' to weave the patterns for me and you
 Tryin' to make the grasses breathe and a grown man cry
 Truth and life is where I gleam
 - Library Magic, The Head and the Heart,
 */

namespace cop3530
{
    //compare and equivalence fxns

    template <typename K>
    bool C(K key1, K key2) { return key1 < key2; }

    template <typename K>
    bool E(K key1, K key2) { return key1 == key2; }

    template <typename K, typename V, bool (*C) (K, K), bool (*E) (K, K)>
    class Map
    {

    public:

        // virtual ~Map() {};
        // //the big 5
        virtual void insert( K key, V value ) = 0;// — adds the specified key-value pair to the map.
        virtual void remove( K key ) = 0;// — removes the specified key-value pair associated with the key.
        virtual V lookup( K key ) = 0;
        virtual bool is_empty() = 0;
        virtual void print() = 0;

    };
}
