/*
 * Multicore Round Robin Scheduling Class (mapped to the SCHED_GRR
 * policy)
 */


static void enqueue_task_grr(struct rq *rq, struct task_struct *p, int wakeup)
{
}

static void dequeue_task_grr(struct rq *rq, struct task_struct *p, int sleep)
{
}

static void requeue_grr_entity(struct grr_rq *grr_rq, struct sched_grr_entity *grr_se, int head)
{
}

static void requeue_task_grr(struct rq *rq, struct task_struct *p, int head)
{
}

static void init_grr_rq(struct grr_rq *grr_rq, struct re *rq) {
	
}
static void yield_task_grr(struct rq *rq)
{
}
static void check_preempt_curr_grr(struct rq *rq, struct task_struct *p, int flags)
{
}

static struct task_struct *pick_next_task_grr(struct rq *rq)
{
}

static void put_prev_task_grr(struct rq *rq, struct task_struct *p)
{
}

#ifdef CONFIG_SMP
static int select_task_rq_grr(struct task_struct *p, int sd_flag, int flags)
{
	return task_cpu(p);
}

static unsigned long
load_balance_grr(struct rq *this_rq, int this_cpu, struct rq *busiest,
                unsigned long max_load_move,
                struct sched_domain *sd, enum cpu_idle_type idle,
                int *all_pinned, int *this_best_prio)
{
        /* don't touch WRR tasks */
        return 0;
}

static int
move_one_task_grr(struct rq *this_rq, int this_cpu, struct rq *busiest,
                 struct sched_domain *sd, enum cpu_idle_type idle)
{
        return 0;
}


#endif
static void set_curr_task_grr(struct rq *rq)
{
	struct task_struct *p = rq->curr;

	p->se.exec_start = rq->clock;
}

static void task_tick_grr(struct rq *rq, struct task_struct *p, int queued)
{
}

unsigned int get_rr_interval_grr(struct task_struct *task)
{
        /*
 *          * Time slice is 0 for SCHED_FIFO tasks
 *                   */
        if (task->policy == SCHED_GRR)
                return DEF_TIMESLICE;
        else
                return 0;
}
/* added by Jia Rao: No preemption, so we leave this function empty */
static void prio_changed_grr(struct rq *rq, struct task_struct *p,
                              int oldprio, int running)
{
}

static void switched_to_grr(struct rq *rq, struct task_struct *p,
                           int running)
{
}

static const struct sched_class grr_sched_class = {
	.next			= &fair_sched_class,
	.enqueue_task		= enqueue_task_grr,
	.dequeue_task		= dequeue_task_grr,
	.yield_task		= yield_task_grr,

	.check_preempt_curr	= check_preempt_curr_grr,

	.pick_next_task		= pick_next_task_grr,
	.put_prev_task		= put_prev_task_grr,

#ifdef CONFIG_SMP
	.select_task_rq		= select_task_rq_grr,

	.load_balance		= load_balance_grr,
	.move_one_task		= move_one_task_grr,
#endif

	.set_curr_task          = set_curr_task_grr,
	.task_tick		= task_tick_grr,

	.get_rr_interval	= get_rr_interval_grr,

//	.prio_changed		= prio_changed_grr,
	.switched_to		= switched_to_grr,
};

