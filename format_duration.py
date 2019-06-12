# Human readable duration format
import re


def format_duration_unit(seconds):
	print(seconds)

	if seconds < 60:
		if seconds == 0:
			return "now"
		elif seconds == 1:
			return "1 second"
		else:
			return "{} seconds".format(seconds)
	elif seconds >= 60 and seconds < 3600:
		mins = seconds // 60
		if mins == 1:
			return "{} minute {}".format(mins, format_duration_unit(seconds % 60))
		else:
			return "{} minutes {}".format(mins, format_duration_unit(seconds % 60))
	elif seconds >= 3600 and seconds < 60*60*24:
		hours = seconds // 3600
		if hours == 1:
			return "{} hour {}".format(hours, format_duration_unit(seconds % 3600))
		else:
			return "{} hours {}".format(hours, format_duration_unit(seconds % 3600))
	elif seconds >= 3600*24 and seconds < 3600*24*365:
		days = seconds // (3600*24)
		if days == 1:
			return "{} day {}".format(days, format_duration_unit(seconds % (3600*24)))
		else:
			return "{} days {}".format(days, format_duration_unit(seconds % (3600*24)))
	elif seconds >= 3600*24*365:
		years = seconds // (3600*24*365)
		if years == 1:
			return "{} year {}".format(years, format_duration_unit(seconds % (3600*24*365)))
		else:
			return "{} years {}".format(years, format_duration_unit(seconds % (3600*24*365)))

def format_duration(seconds):
	print(seconds)
	s = format_duration_unit(seconds)
	print(s)
	slst = re.findall(r'[\d]+[\s][A-z]+|now', s)
	print(slst)

	# eliminate zero if unnecessary.
	if len(slst) > 1:
		slst = slst[:len(slst)-1] if slst.count("now") > 0 else slst

	if len(slst) > 2:
		return ', '.join(slst[:len(slst)-1]) + " and " + slst[-1]
	elif len(slst) == 2:
		return slst[0] + " and " + slst[1]
	else:
		return slst[0]


print(format_duration(15731080))