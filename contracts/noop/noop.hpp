/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#pragma once

#include <eosiolib/eos.hpp>
#include <eosiolib/dispatcher.hpp>
#include <eosiolib/types.hpp>
#include <eosiolib/string.hpp>

using namespace eosio;

namespace noop {
   /**
      noop contract
      All it does is require sender authorization.
      Actions: anyaction
    */


   class noop {
      public:

         ACTION(N(noop), anyaction) {
            anyaction() { }
            anyaction(account_name f, const string& t, const string& d): from(f), type(t), data(d) { }

            account_name from;
            string type;
            string data;

            EOSLIB_SERIALIZE(anyaction, (from)(type)(data))
         };

         static void on(const anyaction& act)
         {
            require_auth(act.from);
         }
   };
} /// noop
