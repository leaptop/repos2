#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <memory>
using std::cout;
using std::endl;
struct KnapsackTask
{
	struct Item
	{
		std::string name;
		unsigned w, v, qty;
		Item() : w(), v(), qty() {}
		Item(const std::string& iname, unsigned iw, unsigned iv, unsigned iqty) :
			name(iname), w(iw), v(iv), qty(iqty)
		{}
	};
	typedef std::vector<Item> Items;
	struct Solution
	{
		unsigned v, w;
		unsigned long long iterations, usec;
		std::vector<unsigned> n;
		Solution() : v(), w(), iterations(), usec() {}
	};
	//...
	KnapsackTask() : maxWeight_(), totalWeight_() {}
	void add(const Item& item)
	{
		const unsigned totalItemWeight = item.w * item.qty;
		if (const bool invalidItem = !totalItemWeight)
			throw std::logic_error("Invalid item: " + item.name);
		totalWeight_ += totalItemWeight;
		items_.push_back(item);
	}
	const Items& getItems() const { return items_; }
	void setMaxWeight(unsigned maxWeight) { maxWeight_ = maxWeight; }
	unsigned getMaxWeight() const { return std::min(totalWeight_, maxWeight_); }

private:
	unsigned maxWeight_, totalWeight_;
	Items items_;
};

class BoundedKnapsackRecursiveSolver
{
public:
	typedef KnapsackTask Task;
	typedef Task::Item Item;
	typedef Task::Items Items;
	typedef Task::Solution Solution;

	void solve(const Task& task)
	{
		Impl(task, solution_).solve();
	}
	const Solution& getSolution() const { return solution_; }
private:
	class Impl
	{
		struct Candidate
		{
			unsigned v, n;
			bool visited;
			Candidate() : v(), n(), visited(false) {}
		};
		typedef std::vector<Candidate> Cache;
	public:
		Impl(const Task& task, Solution& solution) :
			items_(task.getItems()),
			maxWeight_(task.getMaxWeight()),
			maxColumnIndex_(task.getItems().size() - 1),
			solution_(solution),
			cache_(task.getMaxWeight()* task.getItems().size()),
			iterations_(0)
		{}
		void solve()
		{
			if (const bool nothingToSolve = !maxWeight_ || items_.empty())
				return;
			//StopTimer timer;
			Candidate candidate;
			solve(candidate, maxWeight_, items_.size() - 1);
			convertToSolution(candidate);
			//solution_.usec = timer.getTime();
		}
	private:
		void solve(Candidate& current, unsigned reminderWeight, const unsigned itemIndex)
		{
			++iterations_;

			const Item& item(items_[itemIndex]);

			if (const bool firstColumn = !itemIndex)
			{
				const unsigned maxQty = std::min(item.qty, reminderWeight / item.w);
				current.v = item.v * maxQty;
				current.n = maxQty;
				current.visited = true;
			}
			else
			{
				const unsigned nextItemIndex = itemIndex - 1;
				{
					Candidate& nextItem = cachedItem(reminderWeight, nextItemIndex);
					if (!nextItem.visited)
						solve(nextItem, reminderWeight, nextItemIndex);
					current.visited = true;
					current.v = nextItem.v;
					current.n = 0;
				}
				if (reminderWeight >= item.w)
				{
					for (unsigned numberOfItems = 1; numberOfItems <= item.qty; ++numberOfItems)
					{
						reminderWeight -= item.w;
						Candidate& nextItem = cachedItem(reminderWeight, nextItemIndex);
						if (!nextItem.visited)
							solve(nextItem, reminderWeight, nextItemIndex);

						const unsigned checkValue = nextItem.v + numberOfItems * item.v;
						if (checkValue > current.v)
						{
							current.v = checkValue;
							current.n = numberOfItems;
						}
						if (!(reminderWeight >= item.w))
							break;
					}
				}
			}
		}
		void convertToSolution(const Candidate& candidate)
		{
			solution_.iterations = iterations_;
			solution_.v = candidate.v;
			solution_.n.resize(items_.size());

			const Candidate* iter = &candidate;
			unsigned weight = maxWeight_, itemIndex = items_.size() - 1;
			while (true)
			{
				const unsigned currentWeight = iter->n * items_[itemIndex].w;
				solution_.n[itemIndex] = iter->n;
				weight -= currentWeight;
				if (!itemIndex--)
					break;
				iter = &cachedItem(weight, itemIndex);
			}
			solution_.w = maxWeight_ - weight;
		}
		Candidate& cachedItem(unsigned weight, unsigned itemIndex)
		{
			return cache_[weight * maxColumnIndex_ + itemIndex];
		}
		const Items& items_;
		const unsigned maxWeight_;
		const unsigned maxColumnIndex_;
		Solution& solution_;
		Cache cache_;
		unsigned long long iterations_;
	};
	Solution solution_;
};

void populateDataset(KnapsackTask& task)
{
	typedef KnapsackTask::Item Item;
	task.setMaxWeight(100);
	task.add(Item("map", 5, 10, 1000));//1 weight, 2 value, 3 pieces
	task.add(Item("compass", 10, 30, 1000));
	task.add(Item("water", 55, 200, 2000));
}

int main()
{
	KnapsackTask task;
	populateDataset(task);

	BoundedKnapsackRecursiveSolver solver;
	solver.solve(task);
	const KnapsackTask::Solution& solution = solver.getSolution();

	cout << "Iterations to solve: " << solution.iterations << endl;
	cout << "Time to solve: " << solution.usec << " usec" << endl;
	cout << "Solution:" << endl;
	for (unsigned i = 0; i < solution.n.size(); ++i)
	{
		if (const bool itemIsNotInKnapsack = !solution.n[i])
			continue;
		cout << "  " << solution.n[i] << ' ' << task.getItems()[i].name << " ( item weight = " << task.getItems()[i].w << " )" << endl;
	}

	cout << "Weight: " << solution.w << " Value: " << solution.v << endl;
	return 0;
}