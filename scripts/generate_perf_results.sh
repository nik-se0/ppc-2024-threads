#mkdir scripts/perf_stat_dir
source scripts/run_perf_collector.sh &> scripts/perf_stat_dir/perf_log.txt
python3 scripts/create_perf_table.py --input scripts/perf_stat_dir/perf_log.txt --output scripts/perf_stat_dir
