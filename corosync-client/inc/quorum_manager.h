#ifndef QUORUM_MANAGER_H
#define QUORUM_MANAGER_H

#include <corosync/cfg.h>
#include <corosync/quorum.h>
#include <corosync/votequorum.h>
#include "monitor.h"
#include "client_errors.h"
#include "cluster_manager.h"

typedef struct Quorum_Details {
		unsigned int highest_expected;
		unsigned int total_votes;
		unsigned int quorum;
		unsigned int quorate;
		struct votequourm_info *info;
} Quorum_Details ;


//returns a quorum_details struct (see above)
int get_quorum_info(Quorum_Details *qd);
//gets the expected vote
int get_expected_votes(unsigned int *expected_votes);
//sets the expected vote
int set_expected_votes(unsigned int expected_votes);
//gets number of votes held by node #nodeid
int get_votes(uint32_t nodeid, unsigned int *votes);
//sets node #nodeid to have votes = votes
int set_votes(uint32_t nodeid, unsigned int votes);
#endif /* QUORUM_MANAGER_H */