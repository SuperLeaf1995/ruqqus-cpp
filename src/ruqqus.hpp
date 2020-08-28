#ifndef RUQQUS_HPP_INCLUDED
#define RUQQUS_HPP_INCLUDED

#include "guild.hpp"
#include "user.hpp"
#include "post.hpp"
#include "comment.hpp"

class Ruqqus {
    public:
		std::string server;
		
		RuqqusGuild JSON_to_guild(Json::Value val);
		RuqqusUser JSON_to_user(Json::Value val);
		RuqqusPost JSON_to_post(Json::Value val);
		RuqqusComment JSON_to_comment(Json::Value val);
		
        RuqqusGuild guild_info(std::string guildname);
        RuqqusUser user_info(std::string username);
        RuqqusPost post_info(std::string post);
        RuqqusComment comment_info(std::string comment);

        bool guild_available(std::string guildname);
        bool guild_join(std::string guildname);
        bool guild_leave(std::string guildname);
        
        bool user_available(std::string username);
        void user_follow(std::string username);
        void user_unfollow(std::string username);
        
        std::string post_get_title(std::string postid);
		void post_toggle_nsfw(std::string postid);
		void post_delete(std::string postid);
		void post_toggle_nsfl(std::string postid);
		void post_vote(std::string postid, signed char v);
        
        RuqqusComment comment_get_in_post(std::string pid, std::string cid);
        void comment_vote(std::string cid, signed char v);
        
        void admin_ban_user(std::string uid, std::string reason);
		void admin_unban_user(std::string uid);
		void admin_ban_post(std::string pid, std::string reason);
		void admin_unban_post(std::string pid);
		void admin_sticky_post(std::string pid);
		void admin_ban_comment(std::string cid);
		void admin_unban_comment(std::string cid);
		void admin_ban_guild(std::string bid, std::string reason);
		void admin_unban_guild(std::string bid);
		void admin_mod_self(std::string bid);
		Json::Value admin_user_stat(uintmax_t days);
		void admin_csam_nuke(std::string postid);
		void admin_clear_cache();

        Ruqqus(std::string servername);
        ~Ruqqus();
};

#endif // RUQQUS_HPP_INCLUDED
