# Script info
echo "Simple repo puplish to giScript created "
echo "  Create by: Jaroshevskii"
echo "  Version  : 1.0"
echo ""

cd "/home/jaroshevskii/Projects/ravesli/"

# Repo status
git status

# Add all repo changes
git add --all

# Create new commit
git commit -message "Update"

# Push all commis to github
git push
